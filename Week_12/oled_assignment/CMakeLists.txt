cmake_minimum_required(VERSION 3.10)

project(ssd1306_Project VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(OLED_LIB libssd1306)
set(EXE_NAME ssd1306_bin)

set(OLED_SOURCE
        "linux_i2c.c"
        "ssd1306.c"
    )

set(OLED_HEADERS
        "linux_i2c.h"
        "ssd1306.h"
        "font.h"
    )

add_library(${OLED_LIB} STATIC
        ${OLED_SOURCE}
        ${OLED_HEADERS})

set(EXE_SRC 
    "main.c")

add_executable(${EXE_NAME} ${EXE_SRC})

target_link_libraries(${EXE_NAME} PRIVATE ${OLED_LIB})





