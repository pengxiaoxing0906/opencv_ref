cmake_minimum_required(VERSION 3.12)
project(createTrackbar_function)

set(CMAKE_CXX_STANDARD 11)

add_executable(createTrackbar_function main.cpp)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(createTrackbar_function ${OpenCV_LIBS})