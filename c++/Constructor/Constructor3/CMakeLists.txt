cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Constructor3 )

add_executable( Constructor3 Constructor3.cpp InputStream.cpp Stream.cpp )
target_link_libraries( Constructor3 )
