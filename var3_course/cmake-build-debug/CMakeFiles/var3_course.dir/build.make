# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex4/Desktop/2numbers/var3_course

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex4/Desktop/2numbers/var3_course/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/var3_course.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/var3_course.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/var3_course.dir/flags.make

CMakeFiles/var3_course.dir/main.cpp.o: CMakeFiles/var3_course.dir/flags.make
CMakeFiles/var3_course.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex4/Desktop/2numbers/var3_course/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/var3_course.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/var3_course.dir/main.cpp.o -c /home/alex4/Desktop/2numbers/var3_course/main.cpp

CMakeFiles/var3_course.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/var3_course.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex4/Desktop/2numbers/var3_course/main.cpp > CMakeFiles/var3_course.dir/main.cpp.i

CMakeFiles/var3_course.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/var3_course.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex4/Desktop/2numbers/var3_course/main.cpp -o CMakeFiles/var3_course.dir/main.cpp.s

# Object files for target var3_course
var3_course_OBJECTS = \
"CMakeFiles/var3_course.dir/main.cpp.o"

# External object files for target var3_course
var3_course_EXTERNAL_OBJECTS =

var3_course: CMakeFiles/var3_course.dir/main.cpp.o
var3_course: CMakeFiles/var3_course.dir/build.make
var3_course: CMakeFiles/var3_course.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex4/Desktop/2numbers/var3_course/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable var3_course"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/var3_course.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/var3_course.dir/build: var3_course

.PHONY : CMakeFiles/var3_course.dir/build

CMakeFiles/var3_course.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/var3_course.dir/cmake_clean.cmake
.PHONY : CMakeFiles/var3_course.dir/clean

CMakeFiles/var3_course.dir/depend:
	cd /home/alex4/Desktop/2numbers/var3_course/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex4/Desktop/2numbers/var3_course /home/alex4/Desktop/2numbers/var3_course /home/alex4/Desktop/2numbers/var3_course/cmake-build-debug /home/alex4/Desktop/2numbers/var3_course/cmake-build-debug /home/alex4/Desktop/2numbers/var3_course/cmake-build-debug/CMakeFiles/var3_course.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/var3_course.dir/depend

