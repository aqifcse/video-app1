# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/cmake/252/bin/cmake

# The command to remove a file.
RM = /snap/cmake/252/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pc/video-app1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pc/video-app1/build

# Include any dependencies generated for this target.
include CMakeFiles/video-app1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/video-app1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/video-app1.dir/flags.make

CMakeFiles/video-app1.dir/src/main.cpp.o: CMakeFiles/video-app1.dir/flags.make
CMakeFiles/video-app1.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/video-app1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/video-app1.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/video-app1.dir/src/main.cpp.o -c /home/pc/video-app1/src/main.cpp

CMakeFiles/video-app1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/video-app1.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/video-app1/src/main.cpp > CMakeFiles/video-app1.dir/src/main.cpp.i

CMakeFiles/video-app1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/video-app1.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/video-app1/src/main.cpp -o CMakeFiles/video-app1.dir/src/main.cpp.s

CMakeFiles/video-app1.dir/src/load_frame.cpp.o: CMakeFiles/video-app1.dir/flags.make
CMakeFiles/video-app1.dir/src/load_frame.cpp.o: ../src/load_frame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/video-app1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/video-app1.dir/src/load_frame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/video-app1.dir/src/load_frame.cpp.o -c /home/pc/video-app1/src/load_frame.cpp

CMakeFiles/video-app1.dir/src/load_frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/video-app1.dir/src/load_frame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/video-app1/src/load_frame.cpp > CMakeFiles/video-app1.dir/src/load_frame.cpp.i

CMakeFiles/video-app1.dir/src/load_frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/video-app1.dir/src/load_frame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/video-app1/src/load_frame.cpp -o CMakeFiles/video-app1.dir/src/load_frame.cpp.s

# Object files for target video-app1
video__app1_OBJECTS = \
"CMakeFiles/video-app1.dir/src/main.cpp.o" \
"CMakeFiles/video-app1.dir/src/load_frame.cpp.o"

# External object files for target video-app1
video__app1_EXTERNAL_OBJECTS =

video-app1: CMakeFiles/video-app1.dir/src/main.cpp.o
video-app1: CMakeFiles/video-app1.dir/src/load_frame.cpp.o
video-app1: CMakeFiles/video-app1.dir/build.make
video-app1: lib/glfw/src/libglfw3.a
video-app1: /usr/lib/x86_64-linux-gnu/librt.so
video-app1: /usr/lib/x86_64-linux-gnu/libm.so
video-app1: CMakeFiles/video-app1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pc/video-app1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable video-app1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/video-app1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/video-app1.dir/build: video-app1

.PHONY : CMakeFiles/video-app1.dir/build

CMakeFiles/video-app1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/video-app1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/video-app1.dir/clean

CMakeFiles/video-app1.dir/depend:
	cd /home/pc/video-app1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pc/video-app1 /home/pc/video-app1 /home/pc/video-app1/build /home/pc/video-app1/build /home/pc/video-app1/build/CMakeFiles/video-app1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/video-app1.dir/depend

