cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Copy1 )

add_executable( Copy1 Copy1.cpp IntArray.cpp )
target_link_libraries( Copy1 )
