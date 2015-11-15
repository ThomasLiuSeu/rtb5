INCLUDE_DIRECTORIES(../) 

LINK_DIRECTORIES(/usr/include /usr/local/lib /usr/lib/x86_64-linux-gnu/ ${BASE_PATH}/lib)

ADD_EXECUTABLE(click_cgi  click_cgi.cc)
 
TARGET_LINK_LIBRARIES(click_cgi click_pb -lcgicc -lstdc++)

ADD_EXECUTABLE(order_cgi  order_cgi.cc)
 
TARGET_LINK_LIBRARIES(order_cgi order_pb encoding -lcgicc -lgpr -lprotobuf -lglog -lgflags -lstdc++)

ADD_EXECUTABLE(admin_cgi  admin_cgi.cc)
 
TARGET_LINK_LIBRARIES(admin_cgi admin_server_pb encoding -lcgicc -lgpr -lprotobuf -lstdc++)
