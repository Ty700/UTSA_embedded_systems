set(EXE_SRC 
    "main.c")

add_executable(${EXE_NAME} ${EXE_SRC})

target_link_libraries(${EXE_NAME} PRIVATE ${OLED_LIB})

set_target_properties(${EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../../bin")