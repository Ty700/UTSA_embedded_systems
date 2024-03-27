set(EXE_SOURCES
    "main.c")

add_executable(${EXECUTBALE_NAME} ${EXE_SOURCES})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${TRANSLATELIB})