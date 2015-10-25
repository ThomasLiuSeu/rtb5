// Copyright (c) 2011, Tencent Inc.
// All rights reserved.
//
// Author: Eric Liu <ericliu@tencent.com>
// Created: 07/19/11
// Description: protobuf message json deserializer

#ifndef COMMON_ENCODING_JSON_TO_PB_H_
#define COMMON_ENCODING_JSON_TO_PB_H_

#include <string>
#include "common/base/string/string_piece.h"

namespace Json {
class Value;
}  // namespace Json

namespace google {
namespace protobuf {
class Message;
}  // namespace protobuf
}  // namespace google

namespace RTB5 {

bool JsonValueToProtoMessage(
    const Json::Value& json_value,
    google::protobuf::Message* message,
    std::string* error = NULL,
    bool urlencoded = false);

bool JsonToProtoMessage(
    const StringPiece& json_string_piece,
    google::protobuf::Message* message,
    std::string* error = NULL,
    bool urlencoded = false);

}  // namespace RTB5

#endif  // COMMON_ENCODING_JSON_TO_PB_H_
