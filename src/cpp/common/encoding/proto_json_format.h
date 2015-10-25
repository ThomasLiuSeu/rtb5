// Copyright (c) 2014, Tencent Inc.
// All rights reserved.
//
// Author: CHEN Feng <phongchen@tencent.com>

#ifndef COMMON_ENCODING_PROTO_JSON_FORMAT_H_
#define COMMON_ENCODING_PROTO_JSON_FORMAT_H_
#pragma once

#include <string>
#include <google/protobuf/message.h>
#include <json/value.h>

namespace RTB5 {

// Protobuf json format representation
class ProtoJsonFormat {
 private:  // static class
  ProtoJsonFormat();
  ~ProtoJsonFormat();
 public:
  static bool WriteToValue(const google::protobuf::Message& message,
                           Json::Value* output, std::string* error = NULL);
  static bool PrintToStyledString(const google::protobuf::Message& message,
                                  std::string* output,
                                  std::string* error = NULL);
  static bool PrintToFastString(const google::protobuf::Message& message,
                                std::string* output, std::string* error = NULL);
  static bool PrintToString(const google::protobuf::Message& message,
                            std::string * output,
                            std::string* error = NULL);

  static bool ReadFromValue(const Json::Value& input,
                            google::protobuf::Message* output,
                            std::string* error = NULL);
  static bool ParseFromString(const std::string & input,
                              google::protobuf::Message * output,
                              std::string* error = NULL);
};

}  // namespace RTB5

#endif  // COMMON_ENCODING_PROTO_JSON_FORMAT_H_
