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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/negativo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/negativo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/negativo.dir/flags.make

CMakeFiles/negativo.dir/profesor/src/negativo.cpp.o: CMakeFiles/negativo.dir/flags.make
CMakeFiles/negativo.dir/profesor/src/negativo.cpp.o: ../profesor/src/negativo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/negativo.dir/profesor/src/negativo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/negativo.dir/profesor/src/negativo.cpp.o -c /mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes/profesor/src/negativo.cpp

CMakeFiles/negativo.dir/profesor/src/negativo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/negativo.dir/profesor/src/negativo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes/profesor/src/negativo.cpp > CMakeFiles/negativo.dir/profesor/src/negativo.cpp.i

CMakeFiles/negativo.dir/profesor/src/negativo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/negativo.dir/profesor/src/negativo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes/profesor/src/negativo.cpp -o CMakeFiles/negativo.dir/profesor/src/negativo.cpp.s

# Object files for target negativo
negativo_OBJECTS = \
"CMakeFiles/negativo.dir/profesor/src/negativo.cpp.o"

# External object files for target negativo
negativo_EXTERNAL_OBJECTS =

negativo: CMakeFiles/negativo.dir/profesor/src/negativo.cpp.o
negativo: CMakeFiles/negativo.dir/build.make
negativo: libimage.a
negativo: CMakeFiles/negativo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable negativo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/negativo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/negativo.dir/build: negativo

.PHONY : CMakeFiles/negativo.dir/build

CMakeFiles/negativo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/negativo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/negativo.dir/clean

CMakeFiles/negativo.dir/depend:
	cd /mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes /mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes /mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes/cmake-build-debug /mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes/cmake-build-debug /mnt/d/MEGA/Trabajo/Docencia/2022/ED/practicas_ed/solutions_and_proposals/ej01_imagenes/cmake-build-debug/CMakeFiles/negativo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/negativo.dir/depend

