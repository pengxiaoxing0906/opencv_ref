cmake_minimum_required(VERSION 3.12)
project(draw_rectangle)

set(CMAKE_CXX_STANDARD 11)

add_executable(draw_rectangle main.cpp)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(draw_rectangle ${OpenCV_LIBS})