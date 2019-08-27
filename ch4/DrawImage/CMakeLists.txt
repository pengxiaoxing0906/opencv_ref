cmake_minimum_required(VERSION 3.12)
project(DrawImage)

set(CMAKE_CXX_STANDARD 11)

add_executable(DrawImage main.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(DrawImage ${OpenCV_LIBS})