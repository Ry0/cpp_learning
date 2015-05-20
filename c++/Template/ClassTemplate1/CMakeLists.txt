cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( ClassTemplate1 )

add_executable( ClassTemplate1 ClassTemplate1.cpp Array.h )
target_link_libraries( ClassTemplate1 )
