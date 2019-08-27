cmake_minimum_required(VERSION 3.12)
project(picture_blending)

set(CMAKE_CXX_STANDARD 11)

add_executable(picture_blending main.cpp)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(picture_blending ${OpenCV_LIBS})