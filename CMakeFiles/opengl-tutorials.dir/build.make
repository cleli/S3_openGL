# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/cmake/89/bin/cmake

# The command to remove a file.
RM = /snap/cmake/89/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/clelie/Documents/projetOpenGL/S3_openGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/clelie/Documents/projetOpenGL/S3_openGL

# Include any dependencies generated for this target.
include CMakeFiles/opengl-tutorials.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opengl-tutorials.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opengl-tutorials.dir/flags.make

CMakeFiles/opengl-tutorials.dir/src/app.cpp.o: CMakeFiles/opengl-tutorials.dir/flags.make
CMakeFiles/opengl-tutorials.dir/src/app.cpp.o: src/app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clelie/Documents/projetOpenGL/S3_openGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opengl-tutorials.dir/src/app.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl-tutorials.dir/src/app.cpp.o -c /home/clelie/Documents/projetOpenGL/S3_openGL/src/app.cpp

CMakeFiles/opengl-tutorials.dir/src/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl-tutorials.dir/src/app.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clelie/Documents/projetOpenGL/S3_openGL/src/app.cpp > CMakeFiles/opengl-tutorials.dir/src/app.cpp.i

CMakeFiles/opengl-tutorials.dir/src/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl-tutorials.dir/src/app.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clelie/Documents/projetOpenGL/S3_openGL/src/app.cpp -o CMakeFiles/opengl-tutorials.dir/src/app.cpp.s

CMakeFiles/opengl-tutorials.dir/src/cube.cpp.o: CMakeFiles/opengl-tutorials.dir/flags.make
CMakeFiles/opengl-tutorials.dir/src/cube.cpp.o: src/cube.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clelie/Documents/projetOpenGL/S3_openGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/opengl-tutorials.dir/src/cube.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl-tutorials.dir/src/cube.cpp.o -c /home/clelie/Documents/projetOpenGL/S3_openGL/src/cube.cpp

CMakeFiles/opengl-tutorials.dir/src/cube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl-tutorials.dir/src/cube.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clelie/Documents/projetOpenGL/S3_openGL/src/cube.cpp > CMakeFiles/opengl-tutorials.dir/src/cube.cpp.i

CMakeFiles/opengl-tutorials.dir/src/cube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl-tutorials.dir/src/cube.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clelie/Documents/projetOpenGL/S3_openGL/src/cube.cpp -o CMakeFiles/opengl-tutorials.dir/src/cube.cpp.s

CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.o: CMakeFiles/opengl-tutorials.dir/flags.make
CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.o: src/gl-exception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clelie/Documents/projetOpenGL/S3_openGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.o -c /home/clelie/Documents/projetOpenGL/S3_openGL/src/gl-exception.cpp

CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clelie/Documents/projetOpenGL/S3_openGL/src/gl-exception.cpp > CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.i

CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clelie/Documents/projetOpenGL/S3_openGL/src/gl-exception.cpp -o CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.s

CMakeFiles/opengl-tutorials.dir/src/main.cpp.o: CMakeFiles/opengl-tutorials.dir/flags.make
CMakeFiles/opengl-tutorials.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clelie/Documents/projetOpenGL/S3_openGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/opengl-tutorials.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl-tutorials.dir/src/main.cpp.o -c /home/clelie/Documents/projetOpenGL/S3_openGL/src/main.cpp

CMakeFiles/opengl-tutorials.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl-tutorials.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clelie/Documents/projetOpenGL/S3_openGL/src/main.cpp > CMakeFiles/opengl-tutorials.dir/src/main.cpp.i

CMakeFiles/opengl-tutorials.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl-tutorials.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clelie/Documents/projetOpenGL/S3_openGL/src/main.cpp -o CMakeFiles/opengl-tutorials.dir/src/main.cpp.s

CMakeFiles/opengl-tutorials.dir/src/shader.cpp.o: CMakeFiles/opengl-tutorials.dir/flags.make
CMakeFiles/opengl-tutorials.dir/src/shader.cpp.o: src/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clelie/Documents/projetOpenGL/S3_openGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/opengl-tutorials.dir/src/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl-tutorials.dir/src/shader.cpp.o -c /home/clelie/Documents/projetOpenGL/S3_openGL/src/shader.cpp

CMakeFiles/opengl-tutorials.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl-tutorials.dir/src/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clelie/Documents/projetOpenGL/S3_openGL/src/shader.cpp > CMakeFiles/opengl-tutorials.dir/src/shader.cpp.i

CMakeFiles/opengl-tutorials.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl-tutorials.dir/src/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clelie/Documents/projetOpenGL/S3_openGL/src/shader.cpp -o CMakeFiles/opengl-tutorials.dir/src/shader.cpp.s

# Object files for target opengl-tutorials
opengl__tutorials_OBJECTS = \
"CMakeFiles/opengl-tutorials.dir/src/app.cpp.o" \
"CMakeFiles/opengl-tutorials.dir/src/cube.cpp.o" \
"CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.o" \
"CMakeFiles/opengl-tutorials.dir/src/main.cpp.o" \
"CMakeFiles/opengl-tutorials.dir/src/shader.cpp.o"

# External object files for target opengl-tutorials
opengl__tutorials_EXTERNAL_OBJECTS =

bin/opengl-tutorials: CMakeFiles/opengl-tutorials.dir/src/app.cpp.o
bin/opengl-tutorials: CMakeFiles/opengl-tutorials.dir/src/cube.cpp.o
bin/opengl-tutorials: CMakeFiles/opengl-tutorials.dir/src/gl-exception.cpp.o
bin/opengl-tutorials: CMakeFiles/opengl-tutorials.dir/src/main.cpp.o
bin/opengl-tutorials: CMakeFiles/opengl-tutorials.dir/src/shader.cpp.o
bin/opengl-tutorials: CMakeFiles/opengl-tutorials.dir/build.make
bin/opengl-tutorials: /usr/lib/x86_64-linux-gnu/libOpenGL.so
bin/opengl-tutorials: /usr/lib/x86_64-linux-gnu/libGLX.so
bin/opengl-tutorials: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/opengl-tutorials: libGLAD.a
bin/opengl-tutorials: CMakeFiles/opengl-tutorials.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clelie/Documents/projetOpenGL/S3_openGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable bin/opengl-tutorials"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl-tutorials.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opengl-tutorials.dir/build: bin/opengl-tutorials

.PHONY : CMakeFiles/opengl-tutorials.dir/build

CMakeFiles/opengl-tutorials.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opengl-tutorials.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opengl-tutorials.dir/clean

CMakeFiles/opengl-tutorials.dir/depend:
	cd /home/clelie/Documents/projetOpenGL/S3_openGL && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clelie/Documents/projetOpenGL/S3_openGL /home/clelie/Documents/projetOpenGL/S3_openGL /home/clelie/Documents/projetOpenGL/S3_openGL /home/clelie/Documents/projetOpenGL/S3_openGL /home/clelie/Documents/projetOpenGL/S3_openGL/CMakeFiles/opengl-tutorials.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opengl-tutorials.dir/depend

