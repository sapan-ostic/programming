# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/126/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/126/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/agrsapan/Documents/C++ Tutorials"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/macros_functions.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/macros_functions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/macros_functions.dir/flags.make

CMakeFiles/macros_functions.dir/Macros/functions.cpp.o: CMakeFiles/macros_functions.dir/flags.make
CMakeFiles/macros_functions.dir/Macros/functions.cpp.o: ../Macros/functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/macros_functions.dir/Macros/functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/macros_functions.dir/Macros/functions.cpp.o -c "/home/agrsapan/Documents/C++ Tutorials/Macros/functions.cpp"

CMakeFiles/macros_functions.dir/Macros/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/macros_functions.dir/Macros/functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/agrsapan/Documents/C++ Tutorials/Macros/functions.cpp" > CMakeFiles/macros_functions.dir/Macros/functions.cpp.i

CMakeFiles/macros_functions.dir/Macros/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/macros_functions.dir/Macros/functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/agrsapan/Documents/C++ Tutorials/Macros/functions.cpp" -o CMakeFiles/macros_functions.dir/Macros/functions.cpp.s

# Object files for target macros_functions
macros_functions_OBJECTS = \
"CMakeFiles/macros_functions.dir/Macros/functions.cpp.o"

# External object files for target macros_functions
macros_functions_EXTERNAL_OBJECTS =

macros_functions: CMakeFiles/macros_functions.dir/Macros/functions.cpp.o
macros_functions: CMakeFiles/macros_functions.dir/build.make
macros_functions: CMakeFiles/macros_functions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable macros_functions"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/macros_functions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/macros_functions.dir/build: macros_functions

.PHONY : CMakeFiles/macros_functions.dir/build

CMakeFiles/macros_functions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/macros_functions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/macros_functions.dir/clean

CMakeFiles/macros_functions.dir/depend:
	cd "/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/agrsapan/Documents/C++ Tutorials" "/home/agrsapan/Documents/C++ Tutorials" "/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug" "/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug" "/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug/CMakeFiles/macros_functions.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/macros_functions.dir/depend
