cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Average2 )

add_executable( Average2 Average2.cpp InputStream.cpp )
target_link_libraries( Average2 )
