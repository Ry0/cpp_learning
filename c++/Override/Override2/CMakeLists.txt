cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Override2 )

add_executable( Override2 Override2.cpp ArrayStream.cpp InputStream.cpp Stream.cpp )
target_link_libraries( Override2 )
