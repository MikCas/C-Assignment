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
CMAKE_SOURCE_DIR = "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Task1c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task1c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task1c.dir/flags.make

CMakeFiles/Task1c.dir/Task1c.c.obj: CMakeFiles/Task1c.dir/flags.make
CMakeFiles/Task1c.dir/Task1c.c.obj: ../Task1c.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Task1c.dir/Task1c.c.obj"
	C:\Winbuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Task1c.dir\Task1c.c.obj   -c "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\Task1c.c"

CMakeFiles/Task1c.dir/Task1c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Task1c.dir/Task1c.c.i"
	C:\Winbuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\Task1c.c" > CMakeFiles\Task1c.dir\Task1c.c.i

CMakeFiles/Task1c.dir/Task1c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Task1c.dir/Task1c.c.s"
	C:\Winbuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\Task1c.c" -o CMakeFiles\Task1c.dir\Task1c.c.s

CMakeFiles/Task1c.dir/Task1c.c.obj.requires:

.PHONY : CMakeFiles/Task1c.dir/Task1c.c.obj.requires

CMakeFiles/Task1c.dir/Task1c.c.obj.provides: CMakeFiles/Task1c.dir/Task1c.c.obj.requires
	$(MAKE) -f CMakeFiles\Task1c.dir\build.make CMakeFiles/Task1c.dir/Task1c.c.obj.provides.build
.PHONY : CMakeFiles/Task1c.dir/Task1c.c.obj.provides

CMakeFiles/Task1c.dir/Task1c.c.obj.provides.build: CMakeFiles/Task1c.dir/Task1c.c.obj


# Object files for target Task1c
Task1c_OBJECTS = \
"CMakeFiles/Task1c.dir/Task1c.c.obj"

# External object files for target Task1c
Task1c_EXTERNAL_OBJECTS =

Task1c.exe: CMakeFiles/Task1c.dir/Task1c.c.obj
Task1c.exe: CMakeFiles/Task1c.dir/build.make
Task1c.exe: CMakeFiles/Task1c.dir/linklibs.rsp
Task1c.exe: CMakeFiles/Task1c.dir/objects1.rsp
Task1c.exe: CMakeFiles/Task1c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Task1c.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task1c.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task1c.dir/build: Task1c.exe

.PHONY : CMakeFiles/Task1c.dir/build

CMakeFiles/Task1c.dir/requires: CMakeFiles/Task1c.dir/Task1c.c.obj.requires

.PHONY : CMakeFiles/Task1c.dir/requires

CMakeFiles/Task1c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task1c.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task1c.dir/clean

CMakeFiles/Task1c.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\cmake-build-debug" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\cmake-build-debug" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\cmake-build-debug\CMakeFiles\Task1c.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Task1c.dir/depend

