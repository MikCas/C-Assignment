# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/Task2c.c.obj: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/Task2c.c.obj: ../Task2c.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled.dir/Task2c.c.obj"
	C:\Winbuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled.dir\Task2c.c.obj   -c "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2\Task2c.c"

CMakeFiles/untitled.dir/Task2c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/Task2c.c.i"
	C:\Winbuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2\Task2c.c" > CMakeFiles\untitled.dir\Task2c.c.i

CMakeFiles/untitled.dir/Task2c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/Task2c.c.s"
	C:\Winbuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2\Task2c.c" -o CMakeFiles\untitled.dir\Task2c.c.s

CMakeFiles/untitled.dir/Task2c.c.obj.requires:

.PHONY : CMakeFiles/untitled.dir/Task2c.c.obj.requires

CMakeFiles/untitled.dir/Task2c.c.obj.provides: CMakeFiles/untitled.dir/Task2c.c.obj.requires
	$(MAKE) -f CMakeFiles\untitled.dir\build.make CMakeFiles/untitled.dir/Task2c.c.obj.provides.build
.PHONY : CMakeFiles/untitled.dir/Task2c.c.obj.provides

CMakeFiles/untitled.dir/Task2c.c.obj.provides.build: CMakeFiles/untitled.dir/Task2c.c.obj


# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/Task2c.c.obj"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

libuntitled.a: CMakeFiles/untitled.dir/Task2c.c.obj
libuntitled.a: CMakeFiles/untitled.dir/build.make
libuntitled.a: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libuntitled.a"
	$(CMAKE_COMMAND) -P CMakeFiles\untitled.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: libuntitled.a

.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/requires: CMakeFiles/untitled.dir/Task2c.c.obj.requires

.PHONY : CMakeFiles/untitled.dir/requires

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2\cmake-build-debug" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2\cmake-build-debug" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC2\cmake-build-debug\CMakeFiles\untitled.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend

