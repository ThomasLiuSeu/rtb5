cmake_minimum_required(VERSION 2.6)

# compile proto files
set(PROTO_IN click.proto order.proto campaign.proto union.proto user.proto admin_server.proto)
set(PROTO_SRC click.pb.cc order.pb.cc campaign.pb.cc union.pb.cc user.pb.cc admin_server.pb.cc)
set(PROTO_OUT click.pb.h click.pb.cc order.pb.h order.pb.cc campaign.pb.h campaign.pb.cc union.pb.h union.pb.cc user.pb.h user.pb.cc admin_server.pb.h admin_server.pb.cc proto/)
set(PROTO_GRPC_OUT click.grpc.pb.h click.grpc.pb.cc order.grpc.pb.h order.grpc.pb.cc  admin_server.grpc.pb.h admin_server.grpc.pb.cc proto/)

set(PROTOS_PATH .)
set(GRPC_CPP_PLUGIN grpc_cpp_plugin)
set(GRPC_CPP_PLUGIN_PATH /usr/local/bin/grpc_cpp_plugin)

add_custom_command(
    OUTPUT ${PROTO_OUT}
    COMMAND protoc -I ${PROTOS_PATH} --cpp_out . ${PROTO_IN}
    DEPENDS ${PROTO_IN}
)
add_custom_target(proto DEPENDS ${PROTO_OUT})

add_custom_command(
    OUTPUT ${PROTO_GRPC_OUT}
    COMMAND protoc -I ${PROTOS_PATH} --grpc_out=. --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN_PATH} ${PROTO_IN}
    DEPENDS ${PROTO_IN}
)
add_custom_target(grpc_serveice DEPENDS ${PROTO_GRPC_OUT})

aux_source_directory(. SRC_LIST)
list(APPEND SRC_LIST
    ${PROTO_SRC}
)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_VERBOSE_MAKEFILE on)

ADD_LIBRARY(click_pb click.grpc.pb.cc click.pb.cc)
TARGET_LINK_LIBRARIES(click_pb mysqlclient boost_system -L/usr/local/lib -lgrpc++_unsecure -lgrpc -lgpr -lprotobuf -lpthread -ldl -lm)

ADD_LIBRARY(campaign_pb campaign.pb.cc)
TARGET_LINK_LIBRARIES(campaign_pb mysqlclient boost_system -L/usr/local/lib -lgrpc++_unsecure -lgrpc -lgpr -lprotobuf -lpthread -ldl -lm)

ADD_LIBRARY(union_pb union.pb.cc)
TARGET_LINK_LIBRARIES(union_pb mysqlclient boost_system -L/usr/local/lib -lgrpc++_unsecure -lgrpc -lgpr -lprotobuf -lpthread -ldl -lm)

ADD_LIBRARY(user_pb user.pb.cc)
<<<<<<< HEAD
<<<<<<< HEAD
TARGET_LINK_LIBRARIES(user_pb mysqlclient boost_system -L/usr/local/lib -lgrpc++_unsecure -lgrpc -lgpr -lprotobuf -lpthread -ldl -lm)

ADD_LIBRARY(order_pb order.grpc.pb.cc order.pb.cc)
TARGET_LINK_LIBRARIES(order_pb mysqlclient click_pb boost_system -L/usr/local/lib -lgrpc++_unsecure -lgrpc -lgpr -lprotobuf -lpthread -ldl -lm)
=======
TARGET_LINK_LIBRARIES(user_pb mysqlclient boost_system -L/usr/local/lib -lgrpc++_unsecure -lm -lgrpc -lgpr -lprotobuf -lpthread -ldl -lm)

ADD_LIBRARY(order_pb order.grpc.pb.cc order.pb.cc)
TARGET_LINK_LIBRARIES(order_pb mysqlclient boost_system -L/usr/local/lib -lgrpc++_unsecure -lgrpc -lgpr -lprotobuf -lpthread -ldl click_pb -lm)

ADD_LIBRARY(admin_server_pb admin_server.grpc.pb.cc admin_server.pb.cc)
TARGET_LINK_LIBRARIES(admin_server_pb mysqlclient boost_system -L/usr/local/lib -lgrpc++_unsecure -lgrpc -lgpr -lprotobuf -lpthread -ldl click_pb user_pb union_pb campaign_pb -lm)
>>>>>>> 24d7dd385768e388fa1a694539e5226c9edf4863
=======
TARGET_LINK_LIBRARIES(user_pb mysqlclient boost_system -L/usr/local/lib -lgrpc++_unsecure -lm -lgrpc -lgpr -lprotobuf -lpthread -ldl -lm)

ADD_LIBRARY(order_pb order.grpc.pb.cc order.pb.cc)
TARGET_LINK_LIBRARIES(order_pb mysqlclient boost_system -L/usr/local/lib -lgrpc++_unsecure -lgrpc -lgpr -lprotobuf -lpthread -ldl click_pb -lm)

ADD_LIBRARY(admin_server_pb admin_server.grpc.pb.cc admin_server.pb.cc)
TARGET_LINK_LIBRARIES(admin_server_pb mysqlclient boost_system -L/usr/local/lib -lgrpc++_unsecure -lgrpc -lgpr -lprotobuf -lpthread -ldl click_pb user_pb union_pb campaign_pb -lm)
>>>>>>> 24d7dd385768e388fa1a694539e5226c9edf4863
