include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} stl)
add_executable(array_main array.cpp)
add_executable(map_main maps.cpp)
add_executable(unordered_main unordered_map.cpp)
# target_link_libraries(example LINK_PUBLIC libexample)