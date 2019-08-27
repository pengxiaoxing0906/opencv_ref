cmake_minimum_required(VERSION 3.12)
project(Camshift)

set(CMAKE_CXX_STANDARD 11)

add_executable(Camshift main.cpp)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})


target_link_libraries(Camshift ${OpenCV_LIBS})