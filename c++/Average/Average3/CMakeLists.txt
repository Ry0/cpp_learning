cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Average3 )

add_executable( Average3 Average3.cpp ArrayStream.cpp )
target_link_libraries( Average3 )
