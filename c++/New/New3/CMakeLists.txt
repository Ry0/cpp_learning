cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( New3 )

add_executable( New3 New3.cpp ArrayStream.cpp Stream.cpp )
target_link_libraries( New3 )
