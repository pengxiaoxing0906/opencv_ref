cmake_minimum_required(VERSION 3.12)
project(untitledYAML_Write)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitledYAML_Write  main.cpp)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(untitledYAML_Write ${OpenCV_LIBS})