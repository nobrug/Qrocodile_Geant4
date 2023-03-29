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

# Include any dependencies generated for this target.
include purging_magnet/CMakeFiles/PurgMag.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.make

# Include the progress variables for this target.
include purging_magnet/CMakeFiles/PurgMag.dir/progress.make

# Include the compile flags for this target's objects.
include purging_magnet/CMakeFiles/PurgMag.dir/flags.make

purging_magnet/CMakeFiles/PurgMag.dir/PurgMag.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/flags.make
purging_magnet/CMakeFiles/PurgMag.dir/PurgMag.cc.o: ../purging_magnet/PurgMag.cc
purging_magnet/CMakeFiles/PurgMag.dir/PurgMag.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object purging_magnet/CMakeFiles/PurgMag.dir/PurgMag.cc.o"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT purging_magnet/CMakeFiles/PurgMag.dir/PurgMag.cc.o -MF CMakeFiles/PurgMag.dir/PurgMag.cc.o.d -o CMakeFiles/PurgMag.dir/PurgMag.cc.o -c /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/PurgMag.cc

purging_magnet/CMakeFiles/PurgMag.dir/PurgMag.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PurgMag.dir/PurgMag.cc.i"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/PurgMag.cc > CMakeFiles/PurgMag.dir/PurgMag.cc.i

purging_magnet/CMakeFiles/PurgMag.dir/PurgMag.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PurgMag.dir/PurgMag.cc.s"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/PurgMag.cc -o CMakeFiles/PurgMag.dir/PurgMag.cc.s

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/flags.make
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.o: ../purging_magnet/src/PurgMagActionInitializer.cc
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.o"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.o -MF CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.o.d -o CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.o -c /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagActionInitializer.cc

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.i"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagActionInitializer.cc > CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.i

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.s"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagActionInitializer.cc -o CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.s

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/flags.make
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.o: ../purging_magnet/src/PurgMagDetectorConstruction.cc
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.o"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.o -MF CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.o.d -o CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.o -c /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagDetectorConstruction.cc

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.i"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagDetectorConstruction.cc > CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.i

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.s"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagDetectorConstruction.cc -o CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.s

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/flags.make
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.o: ../purging_magnet/src/PurgMagEventAction.cc
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.o"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.o -MF CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.o.d -o CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.o -c /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagEventAction.cc

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.i"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagEventAction.cc > CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.i

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.s"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagEventAction.cc -o CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.s

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/flags.make
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.o: ../purging_magnet/src/PurgMagPhysicsList.cc
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.o"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.o -MF CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.o.d -o CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.o -c /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagPhysicsList.cc

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.i"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagPhysicsList.cc > CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.i

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.s"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagPhysicsList.cc -o CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.s

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/flags.make
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.o: ../purging_magnet/src/PurgMagPrimaryGeneratorAction.cc
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.o"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.o -MF CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.o.d -o CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.o -c /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagPrimaryGeneratorAction.cc

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.i"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagPrimaryGeneratorAction.cc > CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.i

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.s"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagPrimaryGeneratorAction.cc -o CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.s

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/flags.make
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.o: ../purging_magnet/src/PurgMagRunAction.cc
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.o"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.o -MF CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.o.d -o CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.o -c /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagRunAction.cc

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.i"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagRunAction.cc > CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.i

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.s"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagRunAction.cc -o CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.s

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/flags.make
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.o: ../purging_magnet/src/PurgMagSteppingAction.cc
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.o"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.o -MF CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.o.d -o CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.o -c /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagSteppingAction.cc

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.i"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagSteppingAction.cc > CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.i

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.s"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagSteppingAction.cc -o CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.s

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/flags.make
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.o: ../purging_magnet/src/PurgMagSteppingVerbose.cc
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.o"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.o -MF CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.o.d -o CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.o -c /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagSteppingVerbose.cc

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.i"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagSteppingVerbose.cc > CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.i

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.s"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagSteppingVerbose.cc -o CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.s

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/flags.make
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.o: ../purging_magnet/src/PurgMagTabulatedField3D.cc
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.o"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.o -MF CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.o.d -o CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.o -c /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagTabulatedField3D.cc

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.i"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagTabulatedField3D.cc > CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.i

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.s"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagTabulatedField3D.cc -o CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.s

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/flags.make
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.o: ../purging_magnet/src/PurgMagTrackingAction.cc
purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.o: purging_magnet/CMakeFiles/PurgMag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.o"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.o -MF CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.o.d -o CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.o -c /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagTrackingAction.cc

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.i"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagTrackingAction.cc > CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.i

purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.s"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet/src/PurgMagTrackingAction.cc -o CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.s

# Object files for target PurgMag
PurgMag_OBJECTS = \
"CMakeFiles/PurgMag.dir/PurgMag.cc.o" \
"CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.o" \
"CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.o" \
"CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.o" \
"CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.o" \
"CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.o" \
"CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.o" \
"CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.o" \
"CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.o" \
"CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.o" \
"CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.o"

# External object files for target PurgMag
PurgMag_EXTERNAL_OBJECTS =

purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/PurgMag.cc.o
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagActionInitializer.cc.o
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagDetectorConstruction.cc.o
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagEventAction.cc.o
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPhysicsList.cc.o
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagPrimaryGeneratorAction.cc.o
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagRunAction.cc.o
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingAction.cc.o
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagSteppingVerbose.cc.o
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTabulatedField3D.cc.o
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/src/PurgMagTrackingAction.cc.o
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/build.make
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4Tree.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4GMocren.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4visHepRep.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4RayTracer.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4VRML.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4OpenGL.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4gl2ps.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4interfaces.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4persistency.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4error_propagation.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4readout.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4physicslists.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4parmodels.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4FR.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4vis_management.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4modeling.so
purging_magnet/PurgMag: /usr/lib64/libXmu.so
purging_magnet/PurgMag: /usr/lib64/libXext.so
purging_magnet/PurgMag: /usr/lib64/libXt.so
purging_magnet/PurgMag: /usr/lib64/libSM.so
purging_magnet/PurgMag: /usr/lib64/libICE.so
purging_magnet/PurgMag: /usr/lib64/libX11.so
purging_magnet/PurgMag: /usr/lib64/libXm.so
purging_magnet/PurgMag: /usr/lib64/libGLU.so
purging_magnet/PurgMag: /usr/lib64/libGL.so
purging_magnet/PurgMag: /usr/lib64/libQt5OpenGL.so.5.15.2
purging_magnet/PurgMag: /usr/lib64/libQt5PrintSupport.so.5.15.2
purging_magnet/PurgMag: /usr/lib64/libQt5Widgets.so.5.15.2
purging_magnet/PurgMag: /usr/lib64/libQt5Gui.so.5.15.2
purging_magnet/PurgMag: /usr/lib64/libQt5Core.so.5.15.2
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4run.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4event.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4tracking.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4processes.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4analysis.so
purging_magnet/PurgMag: /usr/lib64/libz.so
purging_magnet/PurgMag: /usr/lib64/libexpat.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4digits_hits.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4track.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4particles.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4geometry.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4materials.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4graphics_reps.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4intercoms.so
purging_magnet/PurgMag: /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/lib64/libG4global.so
purging_magnet/PurgMag: /app/cern/clhep_2.4.1.3/lib/libCLHEP-2.4.1.3.so
purging_magnet/PurgMag: purging_magnet/CMakeFiles/PurgMag.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable PurgMag"
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PurgMag.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
purging_magnet/CMakeFiles/PurgMag.dir/build: purging_magnet/PurgMag
.PHONY : purging_magnet/CMakeFiles/PurgMag.dir/build

purging_magnet/CMakeFiles/PurgMag.dir/clean:
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet && $(CMAKE_COMMAND) -P CMakeFiles/PurgMag.dir/cmake_clean.cmake
.PHONY : purging_magnet/CMakeFiles/PurgMag.dir/clean

purging_magnet/CMakeFiles/PurgMag.dir/depend:
	cd /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/purging_magnet /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet /home/uzh/nobrug/Gator_2020/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics/purging_magnet/CMakeFiles/PurgMag.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : purging_magnet/CMakeFiles/PurgMag.dir/depend

