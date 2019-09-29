cmake_minimum_required(VERSION 3.15)

project(Lab02)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(config)

add_subdirectory(src)
add_subdirectory(apps)
add_subdirectory(tests)
