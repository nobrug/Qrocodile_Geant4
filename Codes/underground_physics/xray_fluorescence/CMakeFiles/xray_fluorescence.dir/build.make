# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics

# Utility rule file for xray_fluorescence.

# Include any custom commands dependencies for this target.
include xray_fluorescence/CMakeFiles/xray_fluorescence.dir/compiler_depend.make

# Include the progress variables for this target.
include xray_fluorescence/CMakeFiles/xray_fluorescence.dir/progress.make

xray_fluorescence/CMakeFiles/xray_fluorescence: xray_fluorescence/XrayFluo

xray_fluorescence: xray_fluorescence/CMakeFiles/xray_fluorescence
xray_fluorescence: xray_fluorescence/CMakeFiles/xray_fluorescence.dir/build.make
.PHONY : xray_fluorescence

# Rule to build all files generated by this target.
xray_fluorescence/CMakeFiles/xray_fluorescence.dir/build: xray_fluorescence
.PHONY : xray_fluorescence/CMakeFiles/xray_fluorescence.dir/build

xray_fluorescence/CMakeFiles/xray_fluorescence.dir/clean:
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/xray_fluorescence && $(CMAKE_COMMAND) -P CMakeFiles/xray_fluorescence.dir/cmake_clean.cmake
.PHONY : xray_fluorescence/CMakeFiles/xray_fluorescence.dir/clean

xray_fluorescence/CMakeFiles/xray_fluorescence.dir/depend:
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/xray_fluorescence /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/xray_fluorescence /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/xray_fluorescence/CMakeFiles/xray_fluorescence.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : xray_fluorescence/CMakeFiles/xray_fluorescence.dir/depend

