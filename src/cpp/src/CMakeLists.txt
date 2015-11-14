
INCLUDE_DIRECTORIES(../) 

SET(SOURCE_FILES rtb5_server.cc)

LINK_DIRECTORIES(/usr/include /usr/local/include /usr/lib/x86_64-linux-gnu/ ${BASE_PATH}/lib)

ADD_LIBRARY(database database.cc)

<<<<<<< HEAD
<<<<<<< HEAD
TARGET_LINK_LIBRARIES(database campaign_pb union_pb click_pb mysqlclient boost_system -lstdc++)
=======
TARGET_LINK_LIBRARIES(database campaign_pb union_pb click_pb user_pb mysqlclient boost_system)
>>>>>>> 24d7dd385768e388fa1a694539e5226c9edf4863
=======
TARGET_LINK_LIBRARIES(database campaign_pb union_pb click_pb user_pb mysqlclient boost_system)
>>>>>>> 24d7dd385768e388fa1a694539e5226c9edf4863

ADD_LIBRARY(click_processor click_processor.cc)

TARGET_LINK_LIBRARIES(click_processor database campaign_pb union_pb click_pb mysqlclient boost_system)

ADD_LIBRARY(order_processor order_processor.cc)

TARGET_LINK_LIBRARIES(order_processor database campaign_pb union_pb click_pb mysqlclient boost_system)

ADD_EXECUTABLE(click_server  click_server.cc)

TARGET_LINK_LIBRARIES(click_server click_pb click_processor -lglog -lgflags)

ADD_EXECUTABLE(order_server  order_server.cc)

TARGET_LINK_LIBRARIES(order_server order_pb click_pb user_pb order_processor -lglog -lgflags)

ADD_EXECUTABLE(admin_main admin_main.cc)

<<<<<<< HEAD
<<<<<<< HEAD
TARGET_LINK_LIBRARIES(admin_server click_pb user_pb click_processor -lglog -lgflags -lm)
=======
TARGET_LINK_LIBRARIES(admin_main click_pb user_pb click_processor -lglog -lgflags)
>>>>>>> 24d7dd385768e388fa1a694539e5226c9edf4863
=======
TARGET_LINK_LIBRARIES(admin_main click_pb user_pb click_processor -lglog -lgflags)
>>>>>>> 24d7dd385768e388fa1a694539e5226c9edf4863

set(CMAKE_FIND_LIBRARY_SUFFIXES .a${CMAKE_FIND_LIBRARY_SUFFIXES})

ADD_LIBRARY(http_client http_client.cc)

TARGET_LINK_LIBRARIES(http_client campaign_pb union_pb click_pb mysqlclient boost_system -lcurl)

ADD_LIBRARY(haitao55_order_update_functor haitao55_order_update_functor.cc)

TARGET_LINK_LIBRARIES(haitao55_order_update_functor http_client order_pb -lboost_timer -lboost_date_time -ljsoncpp)

ADD_LIBRARY(viglink_order_update_functor viglink_order_update_functor.cc)

TARGET_LINK_LIBRARIES(viglink_order_update_functor http_client order_pb -lboost_timer -lboost_date_time -ljsoncpp)

ADD_LIBRARY(order_update_processor order_update_processor.cc)

TARGET_LINK_LIBRARIES(order_update_processor database haitao55_order_update_functor viglink_order_update_functor)

ADD_EXECUTABLE(order_update  order_update.cc)
 
TARGET_LINK_LIBRARIES(order_update order_update_processor database haitao55_order_update_functor -lglog -lgflags)

SUBDIRS(./cgi)

SUBDIRS(./server)

SUBDIRS(./admin)

