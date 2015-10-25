cc_library(
    name = 'encoding',
    srcs = [
        'base64.cpp',
        'charset_converter.cc',
        'percent.cpp',
        'json_to_pb.cc',
        'pb_to_json.cc',
        'proto_json_format.cc',
    ],
    deps = [
        '//common/base/string:string',
        '//common/system/concurrency:concurrency',
        '//thirdparty/jsoncpp:jsoncpp',
        '//thirdparty/protobuf:protobuf',
        '//thirdparty/stringencoders:stringencoders',
    ]
)

proto_library(
    name = 'pb_json_test_proto',
    srcs = 'pb_json_test.proto'
)

cc_test(
    name = 'pb_json_test',
    srcs = 'pb_json_test.cc',
    deps = [
        ':encoding',
        ':pb_json_test_proto',
    ]
)

cc_test(
    name = 'base64_test',
    srcs = 'base64_test.cpp',
    deps = ':encoding'
)

cc_test(
    name = 'charset_converter_test',
    srcs = 'charset_converter_test.cc',
    deps = [
        ':encoding'
    ],
)

