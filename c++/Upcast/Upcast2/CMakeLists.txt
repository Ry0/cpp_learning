cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
  -Wall
  -O2
)
project( Upcast2 )

add_executable( Upcast2 Upcast2.cpp InputStream.cpp ArrayStream.cpp Stream.cpp )
target_link_libraries( Upcast2 )
