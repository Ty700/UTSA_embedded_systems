set(TRANSLIB_SRC 
    "translate_to_morse.c")

set(TRANSLIB_HEADER
    "translate_to_morse.h")

add_library(${TRANSLATELIB} STATIC ${TRANSLIB_SRC} ${TRANSLIB_HEADER})

target_include_directories(${TRANSLATELIB} PUBLIC "./")