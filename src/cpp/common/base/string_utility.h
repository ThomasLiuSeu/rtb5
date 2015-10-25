// Copyright (C), 1998-2012, Tencent
// Author: jefftang@tencent.com
// Date: 2012-11-22
#ifndef APP_QZAP_COMMON_BASE_STRING_UTILITY_H_
#define APP_QZAP_COMMON_BASE_STRING_UTILITY_H_
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <vector>
#include "common/base/base.h"
// Return a C++ string
std::string StringPrintf(const char* format, ...)
  __attribute__((format(printf, 1, 2)));

// Store result into a supplied string and return it
const std::string& SStringPrintf(std::string* dst, const char* format, ...)
  __attribute__((format(printf, 2, 3)));

// Append result to a supplied string
void StringAppendF(std::string* dst, const char* format, ...)
  __attribute__((format(printf, 2, 3)));

// Lower-level routine that takes a va_list and appends to a specified
// string.  All other routines are just convenience wrappers around it.
void StringAppendV(std::string* dst, const char* format, va_list ap);
bool SplitString(const std::string &src,
    const char *separators,
    std::vector<std::string> *result);

bool SplitStringByString(const std::string &src,
    const std::string &separator,
    std::vector<std::string> *result);

bool PopenToString(const char *command, std::string *result);
bool PopenFromString(const char *command, const char *input);

void LTrimString(std::string *str);
void RTrimString(std::string *str);
void TrimString(std::string *str);

template <typename T>
bool StringToNumeric(const std::string &s, T *val, int32_t base = 0);

template <typename T>
const std::string ConvertToString(const T &val);

template<> bool StringToNumeric(const std::string &s, int16_t *val, int32_t base);
template<> bool StringToNumeric(const std::string &s, int32_t *val, int32_t base);
template<> bool StringToNumeric(const std::string &s, int64_t *val, int32_t base);
template<> bool StringToNumeric(const std::string &s, uint16_t *val, int32_t base);
template<> bool StringToNumeric(const std::string &s, uint32_t *val, int32_t base);
template<> bool StringToNumeric(const std::string &s, uint64_t *val, int32_t base);
template<> bool StringToNumeric(const std::string &s, float *val, int32_t base);
template<> bool StringToNumeric(const std::string &s, double *val, int32_t base);

template<> const std::string ConvertToString(const int32_t &val);
template<> const std::string ConvertToString(const int64_t &val);
template<> const std::string ConvertToString(const uint32_t &val);
template<> const std::string ConvertToString(const uint64_t &val);
template<> const std::string ConvertToString(const double &val);
template<> inline const std::string ConvertToString(const std::string &val) {
  return val;
}
inline const std::string ConvertToString(const char *val) {
  return std::string(val);
}

void StringReplace(std::string *str, const std::string &from, const std::string &to);

void StringReplaceNonRec(std::string *str, const std::string &from, const std::string &to);

uint32_t ChecksumString(const std::string& str);

// the api of md5sum
std::string MD5sumString(const std::string &str);

// gcc std::string == is quit slow.
static inline bool StringEqual(const std::string &s1, const std::string &s2) {
  return s1.size() == s2.size() &&
    memcmp(s1.c_str(), s2.c_str(), s1.size()) == 0;
}

void StringToLower(std::string * str);

// exp a string like shell.
bool StringExp(const char *exp, std::vector<std::string> *result);

template <typename I>
static inline std::string JoinString(I begin, I end, const std::string &seperator) {
  if (begin == end) {
    return "";
  }
  std::string t(*begin);
  begin++;
  while (begin != end) {
    t = t + seperator + *begin++;
  }
  return t;
}

static inline std::string JoinString(const std::vector<std::string> &field, const std::string &seperator) {
  return JoinString(field.begin(), field.end(), seperator);
}

std::string HexDump(const std::string &s);

template<typename T>
bool SplitNumericString(const std::string& numeric_string,
                        const char* separators,
                        std::vector<T>* numbers)
{
    std::vector<std::string> segs;
    if (!SplitString(numeric_string, separators, &segs))
    {
        return false;
    }
    for (size_t i = 0; i < segs.size(); ++i)
    {
       if(segs[i].empty())
       {
           continue;
       }
       T number;
       if (!StringToNumeric(segs[i], &number))
       {
           return false;
       }
       numbers->push_back(number);
    }
    return true;
}
#endif  // APP_QZAP_COMMON_BASE_STRING_UTILITY_H_
