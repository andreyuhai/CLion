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
CMAKE_SOURCE_DIR = /home/pafadorama/CLionProjects/algorithmHomework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pafadorama/CLionProjects/algorithmHomework/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/algorithmHomework.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algorithmHomework.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algorithmHomework.dir/flags.make

CMakeFiles/algorithmHomework.dir/main.c.o: CMakeFiles/algorithmHomework.dir/flags.make
CMakeFiles/algorithmHomework.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pafadorama/CLionProjects/algorithmHomework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/algorithmHomework.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/algorithmHomework.dir/main.c.o   -c /home/pafadorama/CLionProjects/algorithmHomework/main.c

CMakeFiles/algorithmHomework.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/algorithmHomework.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pafadorama/CLionProjects/algorithmHomework/main.c > CMakeFiles/algorithmHomework.dir/main.c.i

CMakeFiles/algorithmHomework.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/algorithmHomework.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pafadorama/CLionProjects/algorithmHomework/main.c -o CMakeFiles/algorithmHomework.dir/main.c.s

CMakeFiles/algorithmHomework.dir/main.c.o.requires:

.PHONY : CMakeFiles/algorithmHomework.dir/main.c.o.requires

CMakeFiles/algorithmHomework.dir/main.c.o.provides: CMakeFiles/algorithmHomework.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/algorithmHomework.dir/build.make CMakeFiles/algorithmHomework.dir/main.c.o.provides.build
.PHONY : CMakeFiles/algorithmHomework.dir/main.c.o.provides

CMakeFiles/algorithmHomework.dir/main.c.o.provides.build: CMakeFiles/algorithmHomework.dir/main.c.o


CMakeFiles/algorithmHomework.dir/guessingGame.c.o: CMakeFiles/algorithmHomework.dir/flags.make
CMakeFiles/algorithmHomework.dir/guessingGame.c.o: ../guessingGame.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pafadorama/CLionProjects/algorithmHomework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/algorithmHomework.dir/guessingGame.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/algorithmHomework.dir/guessingGame.c.o   -c /home/pafadorama/CLionProjects/algorithmHomework/guessingGame.c

CMakeFiles/algorithmHomework.dir/guessingGame.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/algorithmHomework.dir/guessingGame.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pafadorama/CLionProjects/algorithmHomework/guessingGame.c > CMakeFiles/algorithmHomework.dir/guessingGame.c.i

CMakeFiles/algorithmHomework.dir/guessingGame.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/algorithmHomework.dir/guessingGame.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pafadorama/CLionProjects/algorithmHomework/guessingGame.c -o CMakeFiles/algorithmHomework.dir/guessingGame.c.s

CMakeFiles/algorithmHomework.dir/guessingGame.c.o.requires:

.PHONY : CMakeFiles/algorithmHomework.dir/guessingGame.c.o.requires

CMakeFiles/algorithmHomework.dir/guessingGame.c.o.provides: CMakeFiles/algorithmHomework.dir/guessingGame.c.o.requires
	$(MAKE) -f CMakeFiles/algorithmHomework.dir/build.make CMakeFiles/algorithmHomework.dir/guessingGame.c.o.provides.build
.PHONY : CMakeFiles/algorithmHomework.dir/guessingGame.c.o.provides

CMakeFiles/algorithmHomework.dir/guessingGame.c.o.provides.build: CMakeFiles/algorithmHomework.dir/guessingGame.c.o


# Object files for target algorithmHomework
algorithmHomework_OBJECTS = \
"CMakeFiles/algorithmHomework.dir/main.c.o" \
"CMakeFiles/algorithmHomework.dir/guessingGame.c.o"

# External object files for target algorithmHomework
algorithmHomework_EXTERNAL_OBJECTS =

algorithmHomework: CMakeFiles/algorithmHomework.dir/main.c.o
algorithmHomework: CMakeFiles/algorithmHomework.dir/guessingGame.c.o
algorithmHomework: CMakeFiles/algorithmHomework.dir/build.make
algorithmHomework: CMakeFiles/algorithmHomework.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pafadorama/CLionProjects/algorithmHomework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable algorithmHomework"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/algorithmHomework.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algorithmHomework.dir/build: algorithmHomework

.PHONY : CMakeFiles/algorithmHomework.dir/build

CMakeFiles/algorithmHomework.dir/requires: CMakeFiles/algorithmHomework.dir/main.c.o.requires
CMakeFiles/algorithmHomework.dir/requires: CMakeFiles/algorithmHomework.dir/guessingGame.c.o.requires

.PHONY : CMakeFiles/algorithmHomework.dir/requires

CMakeFiles/algorithmHomework.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/algorithmHomework.dir/cmake_clean.cmake
.PHONY : CMakeFiles/algorithmHomework.dir/clean

CMakeFiles/algorithmHomework.dir/depend:
	cd /home/pafadorama/CLionProjects/algorithmHomework/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pafadorama/CLionProjects/algorithmHomework /home/pafadorama/CLionProjects/algorithmHomework /home/pafadorama/CLionProjects/algorithmHomework/cmake-build-debug /home/pafadorama/CLionProjects/algorithmHomework/cmake-build-debug /home/pafadorama/CLionProjects/algorithmHomework/cmake-build-debug/CMakeFiles/algorithmHomework.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/algorithmHomework.dir/depend

