INCLUDE_DIRECTORIES(../../) 

ADD_LIBRARY(string_utility string_utility.cc)

TARGET_LINK_LIBRARIES(string_utility -lz -lglog -lcrypto)










