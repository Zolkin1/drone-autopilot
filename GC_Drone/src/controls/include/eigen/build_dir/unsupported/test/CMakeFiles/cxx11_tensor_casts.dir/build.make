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
CMAKE_SOURCE_DIR = /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir

# Include any dependencies generated for this target.
include unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/depend.make

# Include the progress variables for this target.
include unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/progress.make

# Include the compile flags for this target's objects.
include unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/flags.make

unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o: unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/flags.make
unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o: ../unsupported/test/cxx11_tensor_casts.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o"
	cd /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir/unsupported/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o -c /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/unsupported/test/cxx11_tensor_casts.cpp

unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.i"
	cd /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir/unsupported/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/unsupported/test/cxx11_tensor_casts.cpp > CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.i

unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.s"
	cd /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir/unsupported/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/unsupported/test/cxx11_tensor_casts.cpp -o CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.s

unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o.requires:

.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o.requires

unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o.provides: unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o.requires
	$(MAKE) -f unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/build.make unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o.provides.build
.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o.provides

unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o.provides.build: unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o


# Object files for target cxx11_tensor_casts
cxx11_tensor_casts_OBJECTS = \
"CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o"

# External object files for target cxx11_tensor_casts
cxx11_tensor_casts_EXTERNAL_OBJECTS =

unsupported/test/cxx11_tensor_casts: unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o
unsupported/test/cxx11_tensor_casts: unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/build.make
unsupported/test/cxx11_tensor_casts: unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cxx11_tensor_casts"
	cd /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir/unsupported/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cxx11_tensor_casts.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/build: unsupported/test/cxx11_tensor_casts

.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/build

unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/requires: unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/cxx11_tensor_casts.cpp.o.requires

.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/requires

unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/clean:
	cd /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir/unsupported/test && $(CMAKE_COMMAND) -P CMakeFiles/cxx11_tensor_casts.dir/cmake_clean.cmake
.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/clean

unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/depend:
	cd /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/unsupported/test /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir/unsupported/test /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/build_dir/unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_casts.dir/depend

