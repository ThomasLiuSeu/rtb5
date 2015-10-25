// Copyright (c) 2011, Tencent Inc.
// All rights reserved.
//
// Author: CHEN Feng <phongchen@tencent.com>

#include "common/encoding/base64.h"
#include "thirdparty/gtest/gtest.h"

const std::string kText = ".<>@???????";
const std::string kBase64Text = "Ljw+QD8/Pz8/Pz8=";
const std::string kRfcWebSafeBase64Text = "Ljw-QD8_Pz8_Pz8=";

// namespace common {

TEST(Base64Test, Encode) {
  std::string result;
  EXPECT_TRUE(Base64::Encode(kText, &result));
  EXPECT_EQ(kBase64Text, result);
}

TEST(Base64Test, Decode) {
  std::string result;
  EXPECT_TRUE(Base64::Decode(kBase64Text, &result));
  EXPECT_EQ(kText, result);
}

TEST(Base64Test, RfcWebSafeEncode) {
  std::string result;
  EXPECT_TRUE(Base64::RfcWebSafeEncode(kText, &result));
  EXPECT_EQ(kRfcWebSafeBase64Text, result);
}

TEST(Base64Test, RfcWebSafeDecode) {
  std::string result;
  EXPECT_FALSE(Base64::Decode(kRfcWebSafeBase64Text, &result));
  EXPECT_TRUE(Base64::RfcWebSafeDecode(kRfcWebSafeBase64Text, &result));
  EXPECT_EQ(kText, result);
}

// } // namespace common
