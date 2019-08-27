cmake_minimum_required(VERSION 3.12)
project(YAML_read)

set(CMAKE_CXX_STANDARD 11)

add_executable(YAML_read main.cpp)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(YAML_read ${OpenCV_LIBS})