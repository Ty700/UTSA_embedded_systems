set(C_LIBRARY_SOURCES
    "int_add.c"
    "int_division.c"
    "int_multiply.c"
    "int_subtract.c")

add_library(${C_LIBRARY} STATIC
            ${C_LIBRARY_SOURCES}
            ${C_LIBRARY_HEADERS}
            )   