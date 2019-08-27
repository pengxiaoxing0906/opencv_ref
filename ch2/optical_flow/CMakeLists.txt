cmake_minimum_required(VERSION 3.12)
project(optical_flow)

set(CMAKE_CXX_STANDARD 11)

add_executable(optical_flow main.cpp)

find_package(OpenCV REQUIRED)
include_directories(${Opencv_INCLUDE_DIRS})
target_link_libraries(optical_flow ${OpenCV_LIBS})