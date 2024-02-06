cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

add_executable(hello main.cpp)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall Wextra")
include_directories(include)