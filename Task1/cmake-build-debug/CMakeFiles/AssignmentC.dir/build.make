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
include CMakeFiles/AssignmentC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AssignmentC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AssignmentC.dir/flags.make

CMakeFiles/AssignmentC.dir/Task1e.c.obj: CMakeFiles/AssignmentC.dir/flags.make
CMakeFiles/AssignmentC.dir/Task1e.c.obj: ../Task1e.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AssignmentC.dir/Task1e.c.obj"
	C:\Winbuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AssignmentC.dir\Task1e.c.obj   -c "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\Task1e.c"

CMakeFiles/AssignmentC.dir/Task1e.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AssignmentC.dir/Task1e.c.i"
	C:\Winbuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\Task1e.c" > CMakeFiles\AssignmentC.dir\Task1e.c.i

CMakeFiles/AssignmentC.dir/Task1e.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AssignmentC.dir/Task1e.c.s"
	C:\Winbuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\Task1e.c" -o CMakeFiles\AssignmentC.dir\Task1e.c.s

CMakeFiles/AssignmentC.dir/Task1e.c.obj.requires:

.PHONY : CMakeFiles/AssignmentC.dir/Task1e.c.obj.requires

CMakeFiles/AssignmentC.dir/Task1e.c.obj.provides: CMakeFiles/AssignmentC.dir/Task1e.c.obj.requires
	$(MAKE) -f CMakeFiles\AssignmentC.dir\build.make CMakeFiles/AssignmentC.dir/Task1e.c.obj.provides.build
.PHONY : CMakeFiles/AssignmentC.dir/Task1e.c.obj.provides

CMakeFiles/AssignmentC.dir/Task1e.c.obj.provides.build: CMakeFiles/AssignmentC.dir/Task1e.c.obj


# Object files for target AssignmentC
AssignmentC_OBJECTS = \
"CMakeFiles/AssignmentC.dir/Task1e.c.obj"

# External object files for target AssignmentC
AssignmentC_EXTERNAL_OBJECTS =

AssignmentC.exe: CMakeFiles/AssignmentC.dir/Task1e.c.obj
AssignmentC.exe: CMakeFiles/AssignmentC.dir/build.make
AssignmentC.exe: CMakeFiles/AssignmentC.dir/linklibs.rsp
AssignmentC.exe: CMakeFiles/AssignmentC.dir/objects1.rsp
AssignmentC.exe: CMakeFiles/AssignmentC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable AssignmentC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AssignmentC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AssignmentC.dir/build: AssignmentC.exe

.PHONY : CMakeFiles/AssignmentC.dir/build

CMakeFiles/AssignmentC.dir/requires: CMakeFiles/AssignmentC.dir/Task1e.c.obj.requires

.PHONY : CMakeFiles/AssignmentC.dir/requires

CMakeFiles/AssignmentC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AssignmentC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AssignmentC.dir/clean

CMakeFiles/AssignmentC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\cmake-build-debug" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\cmake-build-debug" "C:\Users\Owner\Dropbox\Uni\Programming principles in C-CPS1011\AssignmentC\cmake-build-debug\CMakeFiles\AssignmentC.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/AssignmentC.dir/depend

