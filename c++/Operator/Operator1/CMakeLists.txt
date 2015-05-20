cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Operator1 )

add_executable( Operator1 Operator1.cpp IntArray.cpp )
target_link_libraries( Operator1 )
