cmake_minimum_required(VERSION 3.12)
project(DftImage)

set(CMAKE_CXX_STANDARD 11)

add_executable(DftImage main.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpebCV_INCLUDE_DIRS})
target_link_libraries(DftImage ${OpenCV_LIBS})