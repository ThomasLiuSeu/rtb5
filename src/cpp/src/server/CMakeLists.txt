
INCLUDE_DIRECTORIES(../../) 

LINK_DIRECTORIES(/usr/include /usr/local/include  ${BASE_PATH}/lib)

ADD_EXECUTABLE(admin_server admin_server.cc)

TARGET_LINK_LIBRARIES(admin_server admin_processor admin_server_pb -lglog -lgflags)