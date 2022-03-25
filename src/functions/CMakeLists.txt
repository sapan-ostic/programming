include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} functions)
add_executable(functions_main functions_main.cpp)
# target_link_libraries(example LINK_PUBLIC libexample)