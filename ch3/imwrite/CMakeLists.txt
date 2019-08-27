cmake_minimum_required(VERSION 3.12)
project(imwrite)

set(CMAKE_CXX_STANDARD 11)

add_executable(imwrite main.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(imwrite ${OpenCV_LIBS})