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
CMAKE_SOURCE_DIR = /home/tyler/UTSA/Embedded_Systems/morse_code_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tyler/UTSA/Embedded_Systems/morse_code_project/build

# Include any dependencies generated for this target.
include unity/CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include unity/CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include unity/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include unity/CMakeFiles/test.dir/flags.make

unity/CMakeFiles/test.dir/test.c.o: unity/CMakeFiles/test.dir/flags.make
unity/CMakeFiles/test.dir/test.c.o: ../unity/test.c
unity/CMakeFiles/test.dir/test.c.o: unity/CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tyler/UTSA/Embedded_Systems/morse_code_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object unity/CMakeFiles/test.dir/test.c.o"
	cd /home/tyler/UTSA/Embedded_Systems/morse_code_project/build/unity && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT unity/CMakeFiles/test.dir/test.c.o -MF CMakeFiles/test.dir/test.c.o.d -o CMakeFiles/test.dir/test.c.o -c /home/tyler/UTSA/Embedded_Systems/morse_code_project/unity/test.c

unity/CMakeFiles/test.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/test.c.i"
	cd /home/tyler/UTSA/Embedded_Systems/morse_code_project/build/unity && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tyler/UTSA/Embedded_Systems/morse_code_project/unity/test.c > CMakeFiles/test.dir/test.c.i

unity/CMakeFiles/test.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/test.c.s"
	cd /home/tyler/UTSA/Embedded_Systems/morse_code_project/build/unity && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tyler/UTSA/Embedded_Systems/morse_code_project/unity/test.c -o CMakeFiles/test.dir/test.c.s

unity/CMakeFiles/test.dir/unity.c.o: unity/CMakeFiles/test.dir/flags.make
unity/CMakeFiles/test.dir/unity.c.o: ../unity/unity.c
unity/CMakeFiles/test.dir/unity.c.o: unity/CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tyler/UTSA/Embedded_Systems/morse_code_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object unity/CMakeFiles/test.dir/unity.c.o"
	cd /home/tyler/UTSA/Embedded_Systems/morse_code_project/build/unity && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT unity/CMakeFiles/test.dir/unity.c.o -MF CMakeFiles/test.dir/unity.c.o.d -o CMakeFiles/test.dir/unity.c.o -c /home/tyler/UTSA/Embedded_Systems/morse_code_project/unity/unity.c

unity/CMakeFiles/test.dir/unity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/unity.c.i"
	cd /home/tyler/UTSA/Embedded_Systems/morse_code_project/build/unity && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tyler/UTSA/Embedded_Systems/morse_code_project/unity/unity.c > CMakeFiles/test.dir/unity.c.i

unity/CMakeFiles/test.dir/unity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/unity.c.s"
	cd /home/tyler/UTSA/Embedded_Systems/morse_code_project/build/unity && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tyler/UTSA/Embedded_Systems/morse_code_project/unity/unity.c -o CMakeFiles/test.dir/unity.c.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.c.o" \
"CMakeFiles/test.dir/unity.c.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

../bin/test: unity/CMakeFiles/test.dir/test.c.o
../bin/test: unity/CMakeFiles/test.dir/unity.c.o
../bin/test: unity/CMakeFiles/test.dir/build.make
../bin/test: lib/libTRANSLIB.a
../bin/test: unity/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tyler/UTSA/Embedded_Systems/morse_code_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ../../bin/test"
	cd /home/tyler/UTSA/Embedded_Systems/morse_code_project/build/unity && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unity/CMakeFiles/test.dir/build: ../bin/test
.PHONY : unity/CMakeFiles/test.dir/build

unity/CMakeFiles/test.dir/clean:
	cd /home/tyler/UTSA/Embedded_Systems/morse_code_project/build/unity && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : unity/CMakeFiles/test.dir/clean

unity/CMakeFiles/test.dir/depend:
	cd /home/tyler/UTSA/Embedded_Systems/morse_code_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tyler/UTSA/Embedded_Systems/morse_code_project /home/tyler/UTSA/Embedded_Systems/morse_code_project/unity /home/tyler/UTSA/Embedded_Systems/morse_code_project/build /home/tyler/UTSA/Embedded_Systems/morse_code_project/build/unity /home/tyler/UTSA/Embedded_Systems/morse_code_project/build/unity/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unity/CMakeFiles/test.dir/depend

