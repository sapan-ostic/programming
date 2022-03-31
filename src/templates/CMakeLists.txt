include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} templates)
add_executable(templates_main templates_main.cpp)
add_executable(perfect_forwarding perfect_forwarding.cpp)
# target_link_libraries(example LINK_PUBLIC libexample)