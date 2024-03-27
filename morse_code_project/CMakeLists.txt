cmake_minimum_required(VERSION 3.22)

project(CProjectTemplate VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)

#Requires the C17 standard to be used
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_EXTENSIONS OFF)

set(TRANSLATELIB TRANSLIB)
set(EXECUTABLE_NAME Executable)

add_subdirectory(lib)
add_subdirectory(src)
