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
CMAKE_SOURCE_DIR = /home/zach/drone-autopilot/rt-drone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zach/drone-autopilot/rt-drone/build

# Include any dependencies generated for this target.
include CMakeFiles/main.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.out.dir/flags.make

CMakeFiles/main.out.dir/main.cpp.o: CMakeFiles/main.out.dir/flags.make
CMakeFiles/main.out.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zach/drone-autopilot/rt-drone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.out.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.out.dir/main.cpp.o -c /home/zach/drone-autopilot/rt-drone/main.cpp

CMakeFiles/main.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.out.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zach/drone-autopilot/rt-drone/main.cpp > CMakeFiles/main.out.dir/main.cpp.i

CMakeFiles/main.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.out.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zach/drone-autopilot/rt-drone/main.cpp -o CMakeFiles/main.out.dir/main.cpp.s

CMakeFiles/main.out.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/main.out.dir/main.cpp.o.requires

CMakeFiles/main.out.dir/main.cpp.o.provides: CMakeFiles/main.out.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.out.dir/build.make CMakeFiles/main.out.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/main.out.dir/main.cpp.o.provides

CMakeFiles/main.out.dir/main.cpp.o.provides.build: CMakeFiles/main.out.dir/main.cpp.o


CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o: CMakeFiles/main.out.dir/flags.make
CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o: ../modules/src/control_ops.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zach/drone-autopilot/rt-drone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o -c /home/zach/drone-autopilot/rt-drone/modules/src/control_ops.cpp

CMakeFiles/main.out.dir/modules/src/control_ops.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.out.dir/modules/src/control_ops.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zach/drone-autopilot/rt-drone/modules/src/control_ops.cpp > CMakeFiles/main.out.dir/modules/src/control_ops.cpp.i

CMakeFiles/main.out.dir/modules/src/control_ops.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.out.dir/modules/src/control_ops.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zach/drone-autopilot/rt-drone/modules/src/control_ops.cpp -o CMakeFiles/main.out.dir/modules/src/control_ops.cpp.s

CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o.requires:

.PHONY : CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o.requires

CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o.provides: CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.out.dir/build.make CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o.provides.build
.PHONY : CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o.provides

CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o.provides.build: CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o


CMakeFiles/main.out.dir/modules/src/estimator.cpp.o: CMakeFiles/main.out.dir/flags.make
CMakeFiles/main.out.dir/modules/src/estimator.cpp.o: ../modules/src/estimator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zach/drone-autopilot/rt-drone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.out.dir/modules/src/estimator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.out.dir/modules/src/estimator.cpp.o -c /home/zach/drone-autopilot/rt-drone/modules/src/estimator.cpp

CMakeFiles/main.out.dir/modules/src/estimator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.out.dir/modules/src/estimator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zach/drone-autopilot/rt-drone/modules/src/estimator.cpp > CMakeFiles/main.out.dir/modules/src/estimator.cpp.i

CMakeFiles/main.out.dir/modules/src/estimator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.out.dir/modules/src/estimator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zach/drone-autopilot/rt-drone/modules/src/estimator.cpp -o CMakeFiles/main.out.dir/modules/src/estimator.cpp.s

CMakeFiles/main.out.dir/modules/src/estimator.cpp.o.requires:

.PHONY : CMakeFiles/main.out.dir/modules/src/estimator.cpp.o.requires

CMakeFiles/main.out.dir/modules/src/estimator.cpp.o.provides: CMakeFiles/main.out.dir/modules/src/estimator.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.out.dir/build.make CMakeFiles/main.out.dir/modules/src/estimator.cpp.o.provides.build
.PHONY : CMakeFiles/main.out.dir/modules/src/estimator.cpp.o.provides

CMakeFiles/main.out.dir/modules/src/estimator.cpp.o.provides.build: CMakeFiles/main.out.dir/modules/src/estimator.cpp.o


CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o: CMakeFiles/main.out.dir/flags.make
CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o: ../util/src/thread_helpers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zach/drone-autopilot/rt-drone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o -c /home/zach/drone-autopilot/rt-drone/util/src/thread_helpers.cpp

CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zach/drone-autopilot/rt-drone/util/src/thread_helpers.cpp > CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.i

CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zach/drone-autopilot/rt-drone/util/src/thread_helpers.cpp -o CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.s

CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o.requires:

.PHONY : CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o.requires

CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o.provides: CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.out.dir/build.make CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o.provides.build
.PHONY : CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o.provides

CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o.provides.build: CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o


# Object files for target main.out
main_out_OBJECTS = \
"CMakeFiles/main.out.dir/main.cpp.o" \
"CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o" \
"CMakeFiles/main.out.dir/modules/src/estimator.cpp.o" \
"CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o"

# External object files for target main.out
main_out_EXTERNAL_OBJECTS =

main.out: CMakeFiles/main.out.dir/main.cpp.o
main.out: CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o
main.out: CMakeFiles/main.out.dir/modules/src/estimator.cpp.o
main.out: CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o
main.out: CMakeFiles/main.out.dir/build.make
main.out: device-drivers/libdriver-lib.a
main.out: CMakeFiles/main.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zach/drone-autopilot/rt-drone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable main.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.out.dir/build: main.out

.PHONY : CMakeFiles/main.out.dir/build

CMakeFiles/main.out.dir/requires: CMakeFiles/main.out.dir/main.cpp.o.requires
CMakeFiles/main.out.dir/requires: CMakeFiles/main.out.dir/modules/src/control_ops.cpp.o.requires
CMakeFiles/main.out.dir/requires: CMakeFiles/main.out.dir/modules/src/estimator.cpp.o.requires
CMakeFiles/main.out.dir/requires: CMakeFiles/main.out.dir/util/src/thread_helpers.cpp.o.requires

.PHONY : CMakeFiles/main.out.dir/requires

CMakeFiles/main.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.out.dir/clean

CMakeFiles/main.out.dir/depend:
	cd /home/zach/drone-autopilot/rt-drone/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zach/drone-autopilot/rt-drone /home/zach/drone-autopilot/rt-drone /home/zach/drone-autopilot/rt-drone/build /home/zach/drone-autopilot/rt-drone/build /home/zach/drone-autopilot/rt-drone/build/CMakeFiles/main.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.out.dir/depend
