# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/12/bin/cmake/bin/cmake

# The command to remove a file.
RM = /snap/clion/12/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pafadorama/CLionProjects/projectEuler/problem3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pafadorama/CLionProjects/projectEuler/problem3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/problem3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/problem3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/problem3.dir/flags.make

CMakeFiles/problem3.dir/main.c.o: CMakeFiles/problem3.dir/flags.make
CMakeFiles/problem3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pafadorama/CLionProjects/projectEuler/problem3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/problem3.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/problem3.dir/main.c.o   -c /home/pafadorama/CLionProjects/projectEuler/problem3/main.c

CMakeFiles/problem3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/problem3.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pafadorama/CLionProjects/projectEuler/problem3/main.c > CMakeFiles/problem3.dir/main.c.i

CMakeFiles/problem3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/problem3.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pafadorama/CLionProjects/projectEuler/problem3/main.c -o CMakeFiles/problem3.dir/main.c.s

CMakeFiles/problem3.dir/main.c.o.requires:

.PHONY : CMakeFiles/problem3.dir/main.c.o.requires

CMakeFiles/problem3.dir/main.c.o.provides: CMakeFiles/problem3.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/problem3.dir/build.make CMakeFiles/problem3.dir/main.c.o.provides.build
.PHONY : CMakeFiles/problem3.dir/main.c.o.provides

CMakeFiles/problem3.dir/main.c.o.provides.build: CMakeFiles/problem3.dir/main.c.o


# Object files for target problem3
problem3_OBJECTS = \
"CMakeFiles/problem3.dir/main.c.o"

# External object files for target problem3
problem3_EXTERNAL_OBJECTS =

problem3: CMakeFiles/problem3.dir/main.c.o
problem3: CMakeFiles/problem3.dir/build.make
problem3: CMakeFiles/problem3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pafadorama/CLionProjects/projectEuler/problem3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable problem3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/problem3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/problem3.dir/build: problem3

.PHONY : CMakeFiles/problem3.dir/build

CMakeFiles/problem3.dir/requires: CMakeFiles/problem3.dir/main.c.o.requires

.PHONY : CMakeFiles/problem3.dir/requires

CMakeFiles/problem3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/problem3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/problem3.dir/clean

CMakeFiles/problem3.dir/depend:
	cd /home/pafadorama/CLionProjects/projectEuler/problem3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pafadorama/CLionProjects/projectEuler/problem3 /home/pafadorama/CLionProjects/projectEuler/problem3 /home/pafadorama/CLionProjects/projectEuler/problem3/cmake-build-debug /home/pafadorama/CLionProjects/projectEuler/problem3/cmake-build-debug /home/pafadorama/CLionProjects/projectEuler/problem3/cmake-build-debug/CMakeFiles/problem3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/problem3.dir/depend

