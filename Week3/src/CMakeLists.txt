set(EXE_SOURCES
    "main.c")

# Executable
add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})

add_subdirectory(int_arithmetic)
add_subdirectory(double_arithmetic)

target_link_libraries(${EXECUTABLE_NAME} ${C_LIBRARY} ${CXX_LIBRARY})

set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../../bin")


target_include_directories(${C_LIBRARY} PUBLIC "./")
target_include_directories(${CXX_LIBRARY} PUBLIC "./")