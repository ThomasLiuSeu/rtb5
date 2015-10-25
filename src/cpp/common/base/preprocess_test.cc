// Copyright (c) 2011, Tencent Inc.
// All rights reserved.
//
// Author: CHEN Feng <phongchen@tencent.com>
// Created: 12/14/11
// Description: test for preprocess.h

#include "common/base/preprocess.h"
#include "common/base/preprocess_test_helper.h"
#include "thirdparty/gtest/gtest.h"

TEST(Preprocess, Stringize) {
  EXPECT_STREQ("ABC", PP_STRINGIZE(ABC));
}

TEST(Preprocess, Join) {
  EXPECT_EQ(12, PP_JOIN(1, 2));
}

TEST(Preprocess, DisallowInHeader) {
  PP_DISALLOW_IN_HEADER_FILE();
}

TEST(Preprocess, VaNargs) {
  EXPECT_EQ(0, GDT_PP_N_ARGS());
  EXPECT_EQ(1, GDT_PP_N_ARGS(a));
  EXPECT_EQ(2, GDT_PP_N_ARGS(a, b));
  EXPECT_EQ(3, GDT_PP_N_ARGS(a, b, c));
  EXPECT_EQ(4, GDT_PP_N_ARGS(a, b, c, d));
  EXPECT_EQ(5, GDT_PP_N_ARGS(a, b, c, d, e));
  EXPECT_EQ(6, GDT_PP_N_ARGS(a, b, c, d, e, f));
  EXPECT_EQ(7, GDT_PP_N_ARGS(a, b, c, d, e, f, g));
  EXPECT_EQ(8, GDT_PP_N_ARGS(a, b, c, d, e, f, g, h));
  EXPECT_EQ(9, GDT_PP_N_ARGS(a, b, c, d, e, f, g, h, i));
  EXPECT_EQ(10, GDT_PP_N_ARGS(a, b, c, d, e, f, g, h, i, j));
  EXPECT_EQ(11, GDT_PP_N_ARGS(a, b, c, d, e, f, g, h, i, j, k));
  EXPECT_EQ(12, GDT_PP_N_ARGS(a, b, c, d, e, f, g, h, i, j, k, l));
  EXPECT_EQ(13, GDT_PP_N_ARGS(a, b, c, d, e, f, g, h, i, j, k, l, m));
  EXPECT_EQ(14, GDT_PP_N_ARGS(a, b, c, d, e, f, g, h, i, j, k, l, m, n));
  EXPECT_EQ(15, GDT_PP_N_ARGS(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o));
}

TEST(Preprocess, Varargs) {
  EXPECT_EQ("a", GDT_PP_FOR_EACH_ARGS(PP_STRINGIZE, a));
  EXPECT_EQ("ab", GDT_PP_FOR_EACH_ARGS(PP_STRINGIZE, a, b));
  EXPECT_EQ("abc", GDT_PP_FOR_EACH_ARGS(PP_STRINGIZE, a, b, c));
  EXPECT_EQ("abcd", GDT_PP_FOR_EACH_ARGS(PP_STRINGIZE, a, b, c, d));
  EXPECT_EQ("abcde", GDT_PP_FOR_EACH_ARGS(PP_STRINGIZE, a, b, c, d, e));
  EXPECT_EQ("abcdef",
            GDT_PP_FOR_EACH_ARGS(PP_STRINGIZE, a, b, c, d, e, f));
  EXPECT_EQ("abcdefg",
            GDT_PP_FOR_EACH_ARGS(PP_STRINGIZE, a, b, c, d, e, f, g));
  EXPECT_EQ("abcdefgh",
            GDT_PP_FOR_EACH_ARGS(PP_STRINGIZE, a, b, c, d, e, f, g, h));
  EXPECT_EQ("abcdefghi",
            GDT_PP_FOR_EACH_ARGS(PP_STRINGIZE, a, b, c, d, e, f, g, h, i));
  EXPECT_EQ("abcdefghij",
            GDT_PP_FOR_EACH_ARGS(PP_STRINGIZE, a, b, c, d, e, f, g, h, i, j));
  EXPECT_EQ("abcdefghijk",
            GDT_PP_FOR_EACH_ARGS(PP_STRINGIZE,
                a, b, c, d, e, f, g, h, i, j, k));
  EXPECT_EQ("abcdefghijkl",
            GDT_PP_FOR_EACH_ARGS(
                PP_STRINGIZE, a, b, c, d, e, f, g, h, i, j, k, l));
  EXPECT_EQ("abcdefghijklm",
            GDT_PP_FOR_EACH_ARGS(
                PP_STRINGIZE, a, b, c, d, e, f, g, h, i, j, k, l, m));
  EXPECT_EQ("abcdefghijklmn",
            GDT_PP_FOR_EACH_ARGS(
                PP_STRINGIZE,
                a, b, c, d, e, f, g, h, i, j, k, l, m, n));
  EXPECT_EQ("abcdefghijklmno",
            GDT_PP_FOR_EACH_ARGS(
                PP_STRINGIZE,
                a, b, c, d, e, f, g, h, i, j, k, l, m, n, o));
}

#define DEFINE_METHOD(cmd, name) (cmd, name)

#define EXPAND_METHOD_(cmd, name) int name() { return cmd; }
#define EXPAND_METHOD(x) EXPAND_METHOD_ x

#define DEFINE_SERVICE(name, ...) \
  class name { \
   public: /* NOLINT(whitespace/indent) */ \
    GDT_PP_FOR_EACH_ARGS(EXPAND_METHOD, __VA_ARGS__) \
  };

// Define a class with too member functions, both return int
DEFINE_SERVICE(TestService,
  DEFINE_METHOD(1, Echo),
  DEFINE_METHOD(2, Inc)
)

TEST(Preprocess, VaForEach) {
  TestService service;
  EXPECT_EQ(1, service.Echo());
  EXPECT_EQ(2, service.Inc());
}
