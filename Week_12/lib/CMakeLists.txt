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


target_include_directories(${OLED_LIB} PUBLIC "./lib/")