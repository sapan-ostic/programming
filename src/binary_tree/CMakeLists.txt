include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} binary_tree)
add_executable(binary_tree_main main.cpp)
# target_link_libraries(example LINK_PUBLIC libexample)