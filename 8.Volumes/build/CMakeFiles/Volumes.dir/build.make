# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes/build"

# Include any dependencies generated for this target.
include CMakeFiles/Volumes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Volumes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Volumes.dir/flags.make

CMakeFiles/Volumes.dir/main.cpp.o: CMakeFiles/Volumes.dir/flags.make
CMakeFiles/Volumes.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Volumes.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Volumes.dir/main.cpp.o -c "/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes/main.cpp"

CMakeFiles/Volumes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Volumes.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes/main.cpp" > CMakeFiles/Volumes.dir/main.cpp.i

CMakeFiles/Volumes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Volumes.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes/main.cpp" -o CMakeFiles/Volumes.dir/main.cpp.s

CMakeFiles/Volumes.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Volumes.dir/main.cpp.o.requires

CMakeFiles/Volumes.dir/main.cpp.o.provides: CMakeFiles/Volumes.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Volumes.dir/build.make CMakeFiles/Volumes.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Volumes.dir/main.cpp.o.provides

CMakeFiles/Volumes.dir/main.cpp.o.provides.build: CMakeFiles/Volumes.dir/main.cpp.o


# Object files for target Volumes
Volumes_OBJECTS = \
"CMakeFiles/Volumes.dir/main.cpp.o"

# External object files for target Volumes
Volumes_EXTERNAL_OBJECTS =

Volumes: CMakeFiles/Volumes.dir/main.cpp.o
Volumes: CMakeFiles/Volumes.dir/build.make
Volumes: CMakeFiles/Volumes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Volumes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Volumes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Volumes.dir/build: Volumes

.PHONY : CMakeFiles/Volumes.dir/build

CMakeFiles/Volumes.dir/requires: CMakeFiles/Volumes.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Volumes.dir/requires

CMakeFiles/Volumes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Volumes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Volumes.dir/clean

CMakeFiles/Volumes.dir/depend:
	cd "/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes" "/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes" "/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes/build" "/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes/build" "/home/cs18/Desktop/Learning Ray Tracing in next week/8.Volumes/build/CMakeFiles/Volumes.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Volumes.dir/depend

