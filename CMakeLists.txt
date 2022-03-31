cmake_minimum_required(VERSION 3.17)
project(programming)

set(CMAKE_CXX_STANDARD 11)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "DO NOT BUILD in-tree.")
endif()

add_subdirectory(src)
# add_subdirectory(test)