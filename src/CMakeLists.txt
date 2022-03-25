include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} source)
add_executable(instrumentor_example instrumentor_example.cpp)
add_subdirectory(templates)
add_subdirectory(binary_tree)
# target_link_libraries(example LINK_PUBLIC libexample)
 