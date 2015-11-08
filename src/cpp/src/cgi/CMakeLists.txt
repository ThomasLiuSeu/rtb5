INCLUDE_DIRECTORIES(../) 

ADD_EXECUTABLE(click_cgi  click_cgi.cc)
 
TARGET_LINK_LIBRARIES(click_cgi click_pb -lcgicc)

ADD_EXECUTABLE(order_cgi  order_cgi.cc)
 
TARGET_LINK_LIBRARIES(order_cgi order_pb encoding -lcgicc -lgpr -lprotobuf)

ADD_EXECUTABLE(admin_cgi  admin_cgi.cc)
 
TARGET_LINK_LIBRARIES(admin_cgi admin_server_pb encoding -lcgicc -lgpr -lprotobuf)