# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/pxx/Downloads/clion-2018.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/pxx/Downloads/clion-2018.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pxx/Documents/opencv/ch3/picture_blending

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pxx/Documents/opencv/ch3/picture_blending/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/picture_blending.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/picture_blending.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/picture_blending.dir/flags.make

CMakeFiles/picture_blending.dir/main.cpp.o: CMakeFiles/picture_blending.dir/flags.make
CMakeFiles/picture_blending.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pxx/Documents/opencv/ch3/picture_blending/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/picture_blending.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/picture_blending.dir/main.cpp.o -c /home/pxx/Documents/opencv/ch3/picture_blending/main.cpp

CMakeFiles/picture_blending.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/picture_blending.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pxx/Documents/opencv/ch3/picture_blending/main.cpp > CMakeFiles/picture_blending.dir/main.cpp.i

CMakeFiles/picture_blending.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/picture_blending.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pxx/Documents/opencv/ch3/picture_blending/main.cpp -o CMakeFiles/picture_blending.dir/main.cpp.s

# Object files for target picture_blending
picture_blending_OBJECTS = \
"CMakeFiles/picture_blending.dir/main.cpp.o"

# External object files for target picture_blending
picture_blending_EXTERNAL_OBJECTS =

picture_blending: CMakeFiles/picture_blending.dir/main.cpp.o
picture_blending: CMakeFiles/picture_blending.dir/build.make
picture_blending: /usr/local/lib/libopencv_viz.so.3.4.1
picture_blending: /usr/local/lib/libopencv_videostab.so.3.4.1
picture_blending: /usr/local/lib/libopencv_shape.so.3.4.1
picture_blending: /usr/local/lib/libopencv_ml.so.3.4.1
picture_blending: /usr/local/lib/libopencv_photo.so.3.4.1
picture_blending: /usr/local/lib/libopencv_stitching.so.3.4.1
picture_blending: /usr/local/lib/libopencv_dnn.so.3.4.1
picture_blending: /usr/local/lib/libopencv_objdetect.so.3.4.1
picture_blending: /usr/local/lib/libopencv_superres.so.3.4.1
picture_blending: /usr/local/lib/libopencv_calib3d.so.3.4.1
picture_blending: /usr/local/lib/libopencv_features2d.so.3.4.1
picture_blending: /usr/local/lib/libopencv_highgui.so.3.4.1
picture_blending: /usr/local/lib/libopencv_flann.so.3.4.1
picture_blending: /usr/local/lib/libopencv_video.so.3.4.1
picture_blending: /usr/local/lib/libopencv_videoio.so.3.4.1
picture_blending: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
picture_blending: /usr/local/lib/libopencv_imgproc.so.3.4.1
picture_blending: /usr/local/lib/libopencv_core.so.3.4.1
picture_blending: CMakeFiles/picture_blending.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pxx/Documents/opencv/ch3/picture_blending/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable picture_blending"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/picture_blending.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/picture_blending.dir/build: picture_blending

.PHONY : CMakeFiles/picture_blending.dir/build

CMakeFiles/picture_blending.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/picture_blending.dir/cmake_clean.cmake
.PHONY : CMakeFiles/picture_blending.dir/clean

CMakeFiles/picture_blending.dir/depend:
	cd /home/pxx/Documents/opencv/ch3/picture_blending/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pxx/Documents/opencv/ch3/picture_blending /home/pxx/Documents/opencv/ch3/picture_blending /home/pxx/Documents/opencv/ch3/picture_blending/cmake-build-debug /home/pxx/Documents/opencv/ch3/picture_blending/cmake-build-debug /home/pxx/Documents/opencv/ch3/picture_blending/cmake-build-debug/CMakeFiles/picture_blending.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/picture_blending.dir/depend

