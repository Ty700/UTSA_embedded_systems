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
include src/double_arithmetic/CMakeFiles/CPPlibrary.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/double_arithmetic/CMakeFiles/CPPlibrary.dir/compiler_depend.make

# Include the progress variables for this target.
include src/double_arithmetic/CMakeFiles/CPPlibrary.dir/progress.make

# Include the compile flags for this target's objects.
include src/double_arithmetic/CMakeFiles/CPPlibrary.dir/flags.make

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_add.cpp.o: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/flags.make
src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_add.cpp.o: ../src/double_arithmetic/double_add.cpp
src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_add.cpp.o: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_add.cpp.o"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_add.cpp.o -MF CMakeFiles/CPPlibrary.dir/double_add.cpp.o.d -o CMakeFiles/CPPlibrary.dir/double_add.cpp.o -c /app/src/double_arithmetic/double_add.cpp

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_add.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPPlibrary.dir/double_add.cpp.i"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/double_arithmetic/double_add.cpp > CMakeFiles/CPPlibrary.dir/double_add.cpp.i

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_add.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPPlibrary.dir/double_add.cpp.s"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/double_arithmetic/double_add.cpp -o CMakeFiles/CPPlibrary.dir/double_add.cpp.s

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_divide.cpp.o: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/flags.make
src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_divide.cpp.o: ../src/double_arithmetic/double_divide.cpp
src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_divide.cpp.o: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_divide.cpp.o"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_divide.cpp.o -MF CMakeFiles/CPPlibrary.dir/double_divide.cpp.o.d -o CMakeFiles/CPPlibrary.dir/double_divide.cpp.o -c /app/src/double_arithmetic/double_divide.cpp

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_divide.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPPlibrary.dir/double_divide.cpp.i"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/double_arithmetic/double_divide.cpp > CMakeFiles/CPPlibrary.dir/double_divide.cpp.i

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_divide.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPPlibrary.dir/double_divide.cpp.s"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/double_arithmetic/double_divide.cpp -o CMakeFiles/CPPlibrary.dir/double_divide.cpp.s

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_multiply.cpp.o: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/flags.make
src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_multiply.cpp.o: ../src/double_arithmetic/double_multiply.cpp
src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_multiply.cpp.o: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_multiply.cpp.o"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_multiply.cpp.o -MF CMakeFiles/CPPlibrary.dir/double_multiply.cpp.o.d -o CMakeFiles/CPPlibrary.dir/double_multiply.cpp.o -c /app/src/double_arithmetic/double_multiply.cpp

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_multiply.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPPlibrary.dir/double_multiply.cpp.i"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/double_arithmetic/double_multiply.cpp > CMakeFiles/CPPlibrary.dir/double_multiply.cpp.i

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_multiply.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPPlibrary.dir/double_multiply.cpp.s"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/double_arithmetic/double_multiply.cpp -o CMakeFiles/CPPlibrary.dir/double_multiply.cpp.s

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_subtract.cpp.o: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/flags.make
src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_subtract.cpp.o: ../src/double_arithmetic/double_subtract.cpp
src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_subtract.cpp.o: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_subtract.cpp.o"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_subtract.cpp.o -MF CMakeFiles/CPPlibrary.dir/double_subtract.cpp.o.d -o CMakeFiles/CPPlibrary.dir/double_subtract.cpp.o -c /app/src/double_arithmetic/double_subtract.cpp

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_subtract.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPPlibrary.dir/double_subtract.cpp.i"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/double_arithmetic/double_subtract.cpp > CMakeFiles/CPPlibrary.dir/double_subtract.cpp.i

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_subtract.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPPlibrary.dir/double_subtract.cpp.s"
	cd /app/build/src/double_arithmetic && //duo-sdk/riscv64-linux-musl-x86_64/bin/riscv64-unknown-linux-musl-g++ --sysroot=//duo-sdk/rootfs $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/double_arithmetic/double_subtract.cpp -o CMakeFiles/CPPlibrary.dir/double_subtract.cpp.s

# Object files for target CPPlibrary
CPPlibrary_OBJECTS = \
"CMakeFiles/CPPlibrary.dir/double_add.cpp.o" \
"CMakeFiles/CPPlibrary.dir/double_divide.cpp.o" \
"CMakeFiles/CPPlibrary.dir/double_multiply.cpp.o" \
"CMakeFiles/CPPlibrary.dir/double_subtract.cpp.o"

# External object files for target CPPlibrary
CPPlibrary_EXTERNAL_OBJECTS =

src/double_arithmetic/libCPPlibrary.a: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_add.cpp.o
src/double_arithmetic/libCPPlibrary.a: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_divide.cpp.o
src/double_arithmetic/libCPPlibrary.a: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_multiply.cpp.o
src/double_arithmetic/libCPPlibrary.a: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/double_subtract.cpp.o
src/double_arithmetic/libCPPlibrary.a: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/build.make
src/double_arithmetic/libCPPlibrary.a: src/double_arithmetic/CMakeFiles/CPPlibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libCPPlibrary.a"
	cd /app/build/src/double_arithmetic && $(CMAKE_COMMAND) -P CMakeFiles/CPPlibrary.dir/cmake_clean_target.cmake
	cd /app/build/src/double_arithmetic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPPlibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/double_arithmetic/CMakeFiles/CPPlibrary.dir/build: src/double_arithmetic/libCPPlibrary.a
.PHONY : src/double_arithmetic/CMakeFiles/CPPlibrary.dir/build

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/clean:
	cd /app/build/src/double_arithmetic && $(CMAKE_COMMAND) -P CMakeFiles/CPPlibrary.dir/cmake_clean.cmake
.PHONY : src/double_arithmetic/CMakeFiles/CPPlibrary.dir/clean

src/double_arithmetic/CMakeFiles/CPPlibrary.dir/depend:
	cd /app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /app /app/src/double_arithmetic /app/build /app/build/src/double_arithmetic /app/build/src/double_arithmetic/CMakeFiles/CPPlibrary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/double_arithmetic/CMakeFiles/CPPlibrary.dir/depend
