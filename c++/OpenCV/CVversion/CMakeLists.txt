cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -g
  -O2
  -std=c++11
)

project( CVversion )

find_package( OpenCV REQUIRED )

add_executable( CVversion CVversion.cpp )
target_link_libraries( CVversion ${OpenCV_LIBS} )
