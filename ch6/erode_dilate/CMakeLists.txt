cmake_minimum_required(VERSION 3.12)
project(erode_dilate)

set(CMAKE_CXX_STANDARD 11)

add_executable(erode_dilate main.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(erode_dilate ${OpenCV_LIBS})