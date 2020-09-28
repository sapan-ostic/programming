cmake_minimum_required(VERSION 3.17)
project(C___Tutorials)

set(CMAKE_CXX_STANDARD 17)

# Algorithms
add_executable(maps Algorithms/09_Maps/maps.cpp)

# C++
add_executable(basics_vectors C++/07_Vectors/basics_vectors.cpp)

add_executable(macros_functions C++/Macros/functions.cpp)
add_executable(macros_templates C++/Macros/templates.cpp)

add_executable(sharedPointer C++/17_SmartPointers/sharedPointer.cpp)
add_executable(weakPointer C++/17_SmartPointers/weakPointers.cpp)
