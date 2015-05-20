cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Override3 )

add_executable( Override3 Override3.cpp InputStream.cpp Stream.cpp )
target_link_libraries( Override3 )
