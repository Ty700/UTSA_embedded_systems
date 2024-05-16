# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /app/build

# Include any dependencies generated for this target.
include CMakeFiles/cjson_utils-static.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cjson_utils-static.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cjson_utils-static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cjson_utils-static.dir/flags.make

CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.o: CMakeFiles/cjson_utils-static.dir/flags.make
CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.o: ../cJSON_Utils.c
CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.o: CMakeFiles/cjson_utils-static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.o"
	//duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-gcc --sysroot=//duo-sdk/rootfs $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.o -MF CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.o.d -o CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.o -c /app/cJSON_Utils.c

CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.i"
	//duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-gcc --sysroot=//duo-sdk/rootfs $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /app/cJSON_Utils.c > CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.i

CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.s"
	//duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-gcc --sysroot=//duo-sdk/rootfs $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /app/cJSON_Utils.c -o CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.s

# Object files for target cjson_utils-static
cjson_utils__static_OBJECTS = \
"CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.o"

# External object files for target cjson_utils-static
cjson_utils__static_EXTERNAL_OBJECTS =

libcjson_utils.a: CMakeFiles/cjson_utils-static.dir/cJSON_Utils.c.o
libcjson_utils.a: CMakeFiles/cjson_utils-static.dir/build.make
libcjson_utils.a: CMakeFiles/cjson_utils-static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libcjson_utils.a"
	$(CMAKE_COMMAND) -P CMakeFiles/cjson_utils-static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cjson_utils-static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cjson_utils-static.dir/build: libcjson_utils.a
.PHONY : CMakeFiles/cjson_utils-static.dir/build

CMakeFiles/cjson_utils-static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cjson_utils-static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cjson_utils-static.dir/clean

CMakeFiles/cjson_utils-static.dir/depend:
	cd /app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /app /app /app/build /app/build /app/build/CMakeFiles/cjson_utils-static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cjson_utils-static.dir/depend
