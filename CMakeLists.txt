cmake_minimum_required(VERSION 3.17)
project(C___Tutorials)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
# Algorithms
add_executable(test_instrumentor src/test_instrumentor.cpp)
