# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/uday/Desktop/Forge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uday/Desktop/Forge/build

# Include any dependencies generated for this target.
include CMakeFiles/Forge.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Forge.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Forge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Forge.dir/flags.make

CMakeFiles/Forge.dir/src/main.cpp.o: CMakeFiles/Forge.dir/flags.make
CMakeFiles/Forge.dir/src/main.cpp.o: /home/uday/Desktop/Forge/src/main.cpp
CMakeFiles/Forge.dir/src/main.cpp.o: CMakeFiles/Forge.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/uday/Desktop/Forge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Forge.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Forge.dir/src/main.cpp.o -MF CMakeFiles/Forge.dir/src/main.cpp.o.d -o CMakeFiles/Forge.dir/src/main.cpp.o -c /home/uday/Desktop/Forge/src/main.cpp

CMakeFiles/Forge.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Forge.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uday/Desktop/Forge/src/main.cpp > CMakeFiles/Forge.dir/src/main.cpp.i

CMakeFiles/Forge.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Forge.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uday/Desktop/Forge/src/main.cpp -o CMakeFiles/Forge.dir/src/main.cpp.s

# Object files for target Forge
Forge_OBJECTS = \
"CMakeFiles/Forge.dir/src/main.cpp.o"

# External object files for target Forge
Forge_EXTERNAL_OBJECTS =

Forge: CMakeFiles/Forge.dir/src/main.cpp.o
Forge: CMakeFiles/Forge.dir/build.make
Forge: CMakeFiles/Forge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/uday/Desktop/Forge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Forge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Forge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Forge.dir/build: Forge
.PHONY : CMakeFiles/Forge.dir/build

CMakeFiles/Forge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Forge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Forge.dir/clean

CMakeFiles/Forge.dir/depend:
	cd /home/uday/Desktop/Forge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uday/Desktop/Forge /home/uday/Desktop/Forge /home/uday/Desktop/Forge/build /home/uday/Desktop/Forge/build /home/uday/Desktop/Forge/build/CMakeFiles/Forge.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Forge.dir/depend
