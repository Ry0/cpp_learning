cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Override1 )

add_executable( Override1 Override1.cpp InputStream.cpp Stream.cpp )
target_link_libraries( Override1 )
