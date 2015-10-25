// Copyright    (C), 1998-2012, Tencent
// Author: jefftang@tencent.com
// Date: 2012-11-22
#include <wordexp.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <algorithm>
#include <functional>
#include <limits>
#include <glog/logging.h>
#include <zlib.h>
#include <openssl/md5.h>
#include "common/base/string_utility.h"

namespace {
struct local_isnotspace : public std::unary_function<bool, char> {
  bool operator() (char c) const {
    return !isspace(c);
  }
};
}

void StringToLower(std::string * str) {
  for (size_t i = 0; i < str->size(); ++i) {
    str->at(i) = std::tolower(str->at(i));
  }
}

void StringAppendV(std::string* dst, const char* format, va_list ap) {
  // First try with a small fixed size buffer
  char space[1024];

  // It's possible for methods that use a va_list to invalidate
  // the data in it upon use.  The fix is to make a copy
  // of the structure before using it and use that copy instead.
  va_list backup_ap;
  va_copy(backup_ap, ap);
  int result = vsnprintf(space, sizeof(space), format, backup_ap);
  va_end(backup_ap);

  if ((result >= 0) && (result < static_cast<int>(sizeof(space)))) {
    // It fit
    dst->append(space, result);
    return;
  }

  // Repeatedly increase buffer size until it fits
  int length = sizeof(space);
  while (true) {
    if (result < 0) {
      // Older behavior: just try doubling the buffer size
      length *= 2;
    } else {
      // We need exactly "result+1" characters
      length = result+1;
    }
    char* buf = new char[length];

    // Restore the va_list before we use it again
    va_copy(backup_ap, ap);
    result = vsnprintf(buf, length, format, backup_ap);
    va_end(backup_ap);

    if ((result >= 0) && (result < length)) {
      // It fit
      dst->append(buf, result);
      delete[] buf;
      return;
    }
    delete[] buf;
  }
}

std::string StringPrintf(const char* format, ...) {
  va_list ap;
  va_start(ap, format);
  std::string result;
  StringAppendV(&result, format, ap);
  va_end(ap);
  return result;
}

const std::string& SStringPrintf(std::string* dst, const char* format, ...) {
  va_list ap;
  va_start(ap, format);
  dst->clear();
  StringAppendV(dst, format, ap);
  va_end(ap);
  return *dst;
}

void StringAppendF(std::string* dst, const char* format, ...) {
  va_list ap;
  va_start(ap, format);
  StringAppendV(dst, format, ap);
  va_end(ap);
}

uint32_t ChecksumString(const std::string& str) {
  uLong adler = adler32(0L, Z_NULL, 0);
  return adler32(
    adler, reinterpret_cast<const Bytef *>(str.c_str()), str.length());
}
bool SplitString(const std::string &src,
    const char *separators,
    std::vector<std::string> *result) {
  result->clear();
  if (src.empty() || separators == NULL) {
    return false;
  }
  static const int kDictLen = 127;
  char dict[kDictLen] = {'\0'};
  const char *p = separators;
  while (*p) {
    const int pvalue = static_cast<int>(*p);
    if (pvalue > kDictLen || pvalue < 0) {
      return false;
    } else {
      dict[pvalue] = 1;
    }
    ++p;
  }
  size_t last_pos = 0;
  p = src.c_str();
  for (size_t pos = 0; pos < src.size(); ++pos) {
    const int pvalue = static_cast<int>(p[pos]);
    if (pvalue > kDictLen || pvalue < 0) {
      continue;
    } else if (dict[static_cast<int>(pvalue)]) {
      result->push_back(src.substr(last_pos, pos-last_pos));
      last_pos = pos+1;
    }
  }
  if (last_pos == src.size()) {
    result->push_back("");
  } else {
    result->push_back(src.substr(last_pos));
  }
  return true;
}

bool SplitStringByString(const std::string &src,
    const std::string &separator,
    std::vector<std::string> *result) {
  result->clear();
  size_t sep_size = separator.size();
  if (src.empty() || sep_size == 0) {
    return false;
  }
  size_t last_pos = 0;
  size_t pos = std::string::npos;
  while ((pos = src.find(separator, last_pos)) != std::string::npos) {
    result->push_back(src.substr(last_pos, pos-last_pos));
    last_pos = pos + sep_size;
  }
  if (last_pos == src.size()) {
    result->push_back("");
  } else {
    result->push_back(src.substr(last_pos));
  }
  return true;
}

bool PopenToString(const char *command, std::string *result) {
  CHECK(command != NULL);
  CHECK(result != NULL);
  result->clear();
  FILE *fp = popen(command, "r");
  if (!fp) {
    return false;
  }
  char buffer[200];
  while (fgets(buffer, sizeof(buffer), fp)) {
    *result += buffer;
  }
  pclose(fp);
  return true;
}

bool PopenFromString(const char *command, const char *input) {
  CHECK(command != NULL);
  CHECK(input != NULL);
  FILE *fp = popen(command, "w");
  if (!fp) {
    return false;
  }
  fprintf(fp, "%s", input);
  pclose(fp);
  return true;
}
void LTrimString(std::string *str) {
  CHECK(str != NULL);
  std::string::iterator it = find_if(
      str->begin(), str->end(), local_isnotspace());
  str->erase(str->begin(), it);
}
void RTrimString(std::string *str) {
  CHECK(str != NULL);
  std::string::reverse_iterator it = find_if(
      str->rbegin(), str->rend(), local_isnotspace());
  str->erase(it.base(), str->end());
}
void TrimString(std::string *str) {
  CHECK(str != NULL);
  RTrimString(str);
  LTrimString(str);
}

template<> bool StringToNumeric(const std::string &s, int16_t *ret, int32_t base) {
  errno = 0;
  int64_t value;
  char *endptr;
  value = strtol(s.c_str(), &endptr, base);
  if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN))
      || (errno != 0 && value == 0)
      || (errno == 0 && (value > std::numeric_limits<int16_t>::max() ||
         value < std::numeric_limits<int16_t>::min()))) {
    return false;
  }

  if (endptr == s.c_str()) {
    return false;
  }
  *ret = value;
  return true;
}

template<> bool StringToNumeric(const std::string &s, int32_t *ret, int32_t base) {
  errno = 0;
  int64_t value;
  char *endptr;
  value = strtol(s.c_str(), &endptr, base);
  if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN))
      || (errno != 0 && value == 0)
      || (errno == 0 && (value > std::numeric_limits<int32_t>::max() ||
         value < std::numeric_limits<int32_t>::min()))) {
    return false;
  }

  if (endptr == s.c_str()) {
    return false;
  }
  *ret = value;
  return true;
}

template<> bool StringToNumeric(const std::string &s, int64_t *ret, int32_t base) {
  errno = 0;
  int64_t value;
  char *endptr;
  value = strtoll(s.c_str(), &endptr, base);
  if ((errno == ERANGE && (value == LLONG_MAX || value == LLONG_MIN))
      || (errno != 0 && value == 0)) {
    return false;
  }

  if (endptr == s.c_str()) {
    return false;
  }
  *ret = value;
  return true;
}

template<> bool StringToNumeric(const std::string &s, uint16_t *ret, int32_t base) {
  errno = 0;
  uint64_t value;
  char *endptr;
  value = strtoul(s.c_str(), &endptr, base);
  if ((errno == ERANGE && (value == ULONG_MAX || value == 0))
      || (errno != 0 && value == 0)
      || (errno == 0 && value >std::numeric_limits<uint16_t>::max())) {
    return false;
  }

  if (endptr == s.c_str()) {
    return false;
  }
  *ret = value;
  return true;
}

template<> bool StringToNumeric(const std::string &s, uint32_t *ret, int32_t base) {
  errno = 0;
  uint64_t value;
  char *endptr;
  value = strtoul(s.c_str(), &endptr, base);
  if ((errno == ERANGE && (value == ULONG_MAX || value == 0))
      || (errno != 0 && value == 0)
      || (errno == 0 && value >std::numeric_limits<uint32_t>::max())) {
    return false;
  }

  if (endptr == s.c_str()) {
    return false;
  }
  *ret = value;
  return true;
}

template<> bool StringToNumeric(const std::string &s, uint64_t *ret, int32_t base) {
  errno = 0;
  uint64_t value;
  char *endptr;
  value = strtoull(s.c_str(), &endptr, base);
  if ((errno == ERANGE && (value == ULLONG_MAX || value == 0))
      || (errno != 0 && value == 0)) {
    return false;
  }

  if (endptr == s.c_str()) {
    return false;
  }
  *ret = value;
  return true;
}

template<> bool StringToNumeric(const std::string &s, double *ret, int32_t base) {
  errno = 0;
  double value;
  char *endptr;
  value = strtod(s.c_str(), &endptr);
  if (errno == ERANGE) {
    return false;
  }

  if (endptr == s.c_str()) {
    return false;
  }
  *ret = value;
  return true;
}

template<> bool StringToNumeric(const std::string &s, float *ret, int32_t base) {
  errno = 0;
  float value;
  char *endptr;
  value = strtof(s.c_str(), &endptr);
  if (errno == ERANGE) {
    return false;
  }

  if (endptr == s.c_str()) {
    return false;
  }
  *ret = value;
  return true;
}

template<>
const std::string ConvertToString(const int32_t &val) {
  return StringPrintf("%d", val);
}

template<>
const std::string ConvertToString(const int64_t &value) {
  char buf[128] = { 0 };
  char *p = &buf[sizeof(buf) - 2];
  int64_t val = std::abs(value);
  do {
    *p = val % 10 + '0';
    val = val / 10;
    --p;
  } while (val > 0);
  if (value < 0) {
    *p = '-';
    --p;
  }
  return std::string(p + 1);
}

template<>
const std::string ConvertToString(const uint32_t &val) {
  return StringPrintf("%u", val);
}

template<>
const std::string ConvertToString(const double &val) {
  return StringPrintf("%e", val);
}

template<>
const std::string ConvertToString(const uint64_t &value) {
  char buf[128] = { 0 };
  char *p = &buf[sizeof(buf) - 2];
  uint64_t val = value;
  do {
    *p = val % 10 + '0';
    val = val / 10;
    --p;
  } while (val > 0);
  return std::string(p + 1);
}

void StringReplace(std::string *str, const std::string &from, const std::string &to) {
  if (from == to) {
    return;
  }
  CHECK(str);
  std::string::size_type pos = str->find(from);
  while (pos != std::string::npos) {
    str->replace(pos, from.length(), to);
    pos = str->find(from, pos);
  }
}

void StringReplaceNonRec(std::string *str, const std::string &from, const std::string &to) {
  if (from == to) {
    return;
  }
  CHECK(str);
  std::string::size_type pos = str->find(from);
  while (pos != std::string::npos) {
    str->replace(pos, from.length(), to);
    pos = str->find(from, pos + to.length());
  }
}

bool StringExp(const char *exp, std::vector<std::string> *result) {
  wordexp_t p;
  char **w;
  if (0 != wordexp(exp, &p, 0)) {
    LOG(ERROR) << "word fail, error: " << errno << " : " << strerror(errno);
    return false;
  }
  w = p.we_wordv;
  for (uint32_t i=0; i< p.we_wordc; i++) {
    result->push_back(std::string(w[i]));
  }
  wordfree(&p);
  return true;
}

std::string MD5sumString(const std::string &str) {
  static const char kLookupHex[] = "0123456789abcdef";
  unsigned char md[MD5_DIGEST_LENGTH];
  MD5(reinterpret_cast<const unsigned char*>(str.c_str()),
      str.size(), reinterpret_cast<unsigned char*>(&md[0]));
  std::string ret;
  ret.resize(arraysize(md) * 2);
  for (int i = 0; i < arraysize(md); ++i) {
    const int lo = md[i] & 0xF;
    const int hi = (md[i] >> 4) & 0xF;
    ret[2 * i] = kLookupHex[hi];
    ret[2 * i + 1] = kLookupHex[lo];
  }
  return ret;
}

std::string HexDump(const std::string &str) {
  static const char kLookupHex[] = "0123456789abcdef";
  std::string ret;
  ret.resize(str.size() * 2);
  for (size_t i = 0; i < str.size(); ++i) {
    const int lo = str[i] & 0xF;
    const int hi = (str[i] >> 4) & 0xF;
    ret[2 * i] = kLookupHex[hi];
    ret[2 * i + 1] = kLookupHex[lo];
  }
  return ret;
}
