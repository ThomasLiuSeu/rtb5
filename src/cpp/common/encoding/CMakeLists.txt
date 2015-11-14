
INCLUDE_DIRECTORIES(../../) 

ADD_LIBRARY(encoding json_to_pb.cc pb_to_json.cc proto_json_format.cc percent.cpp)

TARGET_LINK_LIBRARIES(encoding string_utility -ljsoncpp -lprotobuf -lgflags)
