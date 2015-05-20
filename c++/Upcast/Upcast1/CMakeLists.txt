cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Upcast1 )

add_executable( Upcast1 Upcast1.cpp InputStream.cpp Stream.cpp )
target_link_libraries( Upcast1 )
