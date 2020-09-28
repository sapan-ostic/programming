cmake_minimum_required(VERSION 3.17)
project(C___Tutorials)

set(CMAKE_CXX_STANDARD 17)

add_executable(basics_vectors Vectors/basics_vectors.cpp)

add_executable(macros_functions Macros/functions.cpp)
add_executable(macros_templates Macros/templates.cpp)

add_executable(sharedPointer SmartPointers/sharedPointer.cpp)
add_executable(weakPointer SmartPointers/weakPointers.cpp)
