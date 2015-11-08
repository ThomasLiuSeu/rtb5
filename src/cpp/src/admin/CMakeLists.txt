
INCLUDE_DIRECTORIES(../../) 

LINK_DIRECTORIES(/usr/include /usr/local/include  ${BASE_PATH}/lib)

ADD_LIBRARY(admin_processor admin_processor.cc)

TARGET_LINK_LIBRARIES(admin_processor database campaign_pb union_pb user_pb mysqlclient boost_system)
