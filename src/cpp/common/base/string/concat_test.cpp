// Copyright (c) 2011, Tencent Inc.
// All rights reserved.
//
// Author: CHEN Feng <phongchen@tencent.com>
// Created: 04/30/11
// Description: test string concat

#include "common/base/string/concat.h"
#include "common/base/string/concat_test.pb.h"
#include "thirdparty/gtest/gtest.h"
#include "thirdparty/perftools/profiler.h"
#include "thirdparty/protobuf/text_format.h"

#include "common/base/string_utility.h"

// namespace common {

namespace {

enum NamedEnum {
  N_FIRST,
  N_SECOND
};

// Anonymous enum
enum {
  A_FIRST,
  A_SECOND
};

} // namespace

TEST(StringConcat, Enum) {
  // local enum
  enum {
    L_FIRST,
    L_SECOND
  };

  std::string s;
  StringAppend(&s, N_FIRST);
  EXPECT_EQ("0", s);
  StringAppend(&s, A_FIRST);
  EXPECT_EQ("00", s);
  StringAppend(&s, L_FIRST);
  EXPECT_EQ("000", s);
  EXPECT_EQ("0", StringConcat(N_FIRST));

  // The following code can't compile because anonymous and local enums
  // has no linkage
#if 0
  EXPECT_EQ("0", StringConcat(A_FIRST));
  EXPECT_EQ("0", StringConcat(L_FIRST));
#endif
}

TEST(StringConcat, Append) {
  std::string s = "hello";
  StringAppend(&s, "world");
  EXPECT_EQ("helloworld", s);
}

TEST(StringConcat, Concat) {
  EXPECT_EQ("12580", StringConcat(12580));
  EXPECT_EQ("helloworld", StringConcat("hello", "world"));
  EXPECT_EQ("hello,world", StringConcat("hello", ",", "world"));
  EXPECT_EQ("xxx1024", StringConcat("xxx", 1024));
  EXPECT_EQ("xxx,1024", StringConcat("xxx", ",", 1024));
  EXPECT_EQ("xxx1024-1024", StringConcat("xxx", 1024, -1024));
  EXPECT_EQ("xxx1", StringConcat("xxx", static_cast<uint16_t>(1)));
  EXPECT_EQ("012345678910ABCDEFGHIJKLMNOPQRSTU",
            StringConcat(static_cast<short>(0), static_cast<unsigned short>(1),
                         2, 3U, 4L, 5ULL, 6LL, 7ULL, 8.0f, 9.0, 10.0L,
                         "A", "B", "C", "D", "E", 'F', 'G', 'H', 'I', 'J',
                         'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                         'U'));
}

TEST(StringConcat, ConcatTo) {
  std::string s = "hello";
  StringConcatTo(&s, "world");
  EXPECT_EQ("world", s);
  StringConcatTo(&s, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                 "A", "B", "C", "D", "E", 'F', 'G', 'H', 'I', 'J',
                 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                 'U', 'V');
  EXPECT_EQ("0123456789ABCDEFGHIJKLMNOPQRSTUV", s);
}

///////////////////////////////////////////////////////////////////////////////
// ExtensionTest

class StringConcatExtensionTest : public testing::Test {};

struct SupportOss {
  int a;
  int b;
};

struct CustomType {
  int a;
  long b;
};

template <typename A, typename B>
struct GenericType {
  A a;
  B b;
};

std::ostream& operator<<(std::ostream& oss, const SupportOss& o) {
  return oss << "(" << o.a << ", " << o.b << ")";
}

void StringAppend(std::string* str, const CustomType& o) {
  StringAppend(str, "(", o.a, ", ", o.b, ")");
}

template <typename A, typename B>
void StringAppend(std::string* str, const GenericType<A, B>& o) {
  StringAppend(str, "(", o.a, ", ", o.b, ")");
}

TEST_F(StringConcatExtensionTest, SupportOss) {
  SupportOss o = {1, 2};
  EXPECT_EQ("(1, 2)", StringConcat(o));
}

TEST_F(StringConcatExtensionTest, CustomType) {
  CustomType o = {3, 4};
  EXPECT_EQ("(3, 4)", StringConcat(o));
}

TEST_F(StringConcatExtensionTest, GenericType) {
  GenericType<int, long> o = {3, 4};
  EXPECT_EQ("(3, 4)", StringConcat(o));
}

///////////////////////////////////////////////////////////////////////////////
// PerformanceTest

class PerformanceTest : public testing::Test {};

const int kTestLoopCount = 500000;

TEST_F(PerformanceTest, Concat) {
  std::string s;
  for (int i = 0; i < kTestLoopCount; ++i)
    s = StringConcat(i, i, i, i, i, i, i, i, i, i);
}

TEST_F(PerformanceTest, ConcatTo) {
  std::string s;
  for (int i = 0; i < kTestLoopCount; ++i)
    StringConcatTo(&s, i, i, i, i, i, i, i, i, i, i);
}

TEST_F(PerformanceTest, Format) {
  std::string s;
  for (int i = 0; i < kTestLoopCount; ++i)
    SStringPrintf(&s, "%d%d%d%d%d%d%d%d%d%d", i, i, i, i, i, i, i, i, i, i);
}

TEST_F(PerformanceTest, StringStream) {
  std::string s;
  for (int i = 0; i < kTestLoopCount; ++i) {
    std::ostringstream oss;
    oss << i << i << i << i << i << i << i << i << i << i;
    s = oss.str();
  }
}

TEST_F(PerformanceTest, StringConcatTo) {
  std::string result;
  for (int i = 0; i < kTestLoopCount; ++i) {
    StringConcatTo(&result,
                   "hello", ",", "world",
                   100000000,
                   200000000,
                   300000000,
                   400000000,
                   500000000,
                   "\xFF\x95\x27",
                   "ABCD",
                   "ABCD",
                   1, 2, 3);
  }
}

TEST_F(PerformanceTest, ProtoBuf) {
  common::base::string::concat::test::TestMessage msg;
  msg.set_s1("hello");
  msg.set_s2(",");
  msg.set_s3("world");
  msg.set_n4(100000000);
  msg.set_n5(200000000);
  msg.set_n6(300000000);
  msg.set_n7(400000000);
  msg.set_n8(500000000);
  msg.set_f9("\xFF\x95\x27");
  msg.mutable_m10()->set_s1("ABCD");
  msg.mutable_m10()->set_s2("ABCD");
  msg.mutable_m10()->add_n3(1);
  msg.mutable_m10()->add_n3(2);
  msg.mutable_m10()->add_n3(3);
  std::string str;
  google::protobuf::TextFormat::PrintToString(msg, &str);
  std::cout << str << std::endl;
  std::string result;
  for (int i = 0; i < kTestLoopCount; ++i)
    msg.SerializeToString(&result);
}

int main(int argc, char** argv) {
  ProfilerStart(argv[0]);
  testing::InitGoogleTest(&argc, argv);
  int n = RUN_ALL_TESTS();
  ProfilerStop();
  return n;
}

// } // namespace common
