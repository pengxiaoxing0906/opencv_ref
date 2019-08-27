cmake_minimum_required(VERSION 3.12)
project(SetMouseCakkback)

set(CMAKE_CXX_STANDARD 11)

add_executable(SetMouseCallback main.cpp)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(SetMouseCallback ${OpenCV_LIBS})