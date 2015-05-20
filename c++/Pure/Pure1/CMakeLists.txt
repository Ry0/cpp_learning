cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Pure1 )

add_executable( Pure1 Pure1.cpp InputStream.cpp Stream.cpp )
target_link_libraries( Pure1 )
