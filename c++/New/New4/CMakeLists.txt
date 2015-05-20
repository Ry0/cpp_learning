cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( New4 )

add_executable( New4 New4.cpp ArrayStream.cpp InputStream.cpp Stream.cpp )
target_link_libraries( New4 )
