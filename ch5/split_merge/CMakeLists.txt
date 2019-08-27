cmake_minimum_required(VERSION 3.12)
project(split_merge)

set(CMAKE_CXX_STANDARD 11)

add_executable(split_merge main.cpp)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(split_merge ${OpenCV_LIBS})