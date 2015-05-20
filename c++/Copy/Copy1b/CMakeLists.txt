cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Copy1b )

add_executable( Copy1b Copy1b.cpp IntArray.cpp )
target_link_libraries( Copy1b )
