cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Average3a )

add_executable( Average3a Average3a.cpp ArrayStream.cpp Stream.cpp )
target_link_libraries( Average3a )
