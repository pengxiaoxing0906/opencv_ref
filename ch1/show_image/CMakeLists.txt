cmake_minimum_required(VERSION 3.12)
project(show_image)

set(CMAKE_CXX_STANDARD 11)

add_executable(show_image main.cpp)

#寻找opencv库
#find_package(OpenCV REQUIRED)

#添加头文件
#include_directories(${OpenCV_INCLUDE_DIRS})

#链接OpenCV库
#target_link_libraries(show_image ${OpenCV_LIBS})