set(CXX_LIBRARY_SOURCES
    "double_add.cpp"
    "double_divide.cpp"
    "double_multiply.cpp"
    "double_subtract.cpp")

add_library(${CXX_LIBRARY} SHARED
            ${CXX_LIBRARY_SOURCES}
            ${CXX_LIBRARY_HEADERS}
            )   