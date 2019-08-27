cmake_minimum_required(VERSION 3.12)
project(contrast_brightness)

set(CMAKE_CXX_STANDARD 11)

add_executable(contrast_brightness  main.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(contrast_brightness ${OpenCV_LIBS})