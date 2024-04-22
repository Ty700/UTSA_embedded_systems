cmake_minimum_required(VERSION 3.10)

project(ssd1306_Project VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(OLED_LIB libssd1306)
set(EXE_NAME ssd1306_bin)

add_subdirectory(lib)

set(EXE_SRC 
    "main.c")

add_executable(${EXE_NAME} ${EXE_SRC})

target_link_libraries(${EXE_NAME} PRIVATE ${OLED_LIB})

set_target_properties(${EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../../bin")

target_include_directories(${EXE_NAME} PRIVATE "./lib/")






