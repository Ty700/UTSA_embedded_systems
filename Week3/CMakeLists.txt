cmake_minimum_required(VERSION 3.10)

project(StaticLibExample VERSION 1.0.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(C_LIBRARY Clibrary)
set(CXX_LIBRARY CPPlibrary)
set(EXECUTABLE_NAME Executable)

add_subdirectory(src)
add_subdirectory(include)