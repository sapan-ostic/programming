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
include CMakeFiles/weakPointer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/weakPointer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/weakPointer.dir/flags.make

CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.o: CMakeFiles/weakPointer.dir/flags.make
CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.o: ../SmartPointers/weakPointers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.o -c "/home/agrsapan/Documents/C++ Tutorials/SmartPointers/weakPointers.cpp"

CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/agrsapan/Documents/C++ Tutorials/SmartPointers/weakPointers.cpp" > CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.i

CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/agrsapan/Documents/C++ Tutorials/SmartPointers/weakPointers.cpp" -o CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.s

# Object files for target weakPointer
weakPointer_OBJECTS = \
"CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.o"

# External object files for target weakPointer
weakPointer_EXTERNAL_OBJECTS =

weakPointer: CMakeFiles/weakPointer.dir/SmartPointers/weakPointers.cpp.o
weakPointer: CMakeFiles/weakPointer.dir/build.make
weakPointer: CMakeFiles/weakPointer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable weakPointer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/weakPointer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/weakPointer.dir/build: weakPointer

.PHONY : CMakeFiles/weakPointer.dir/build

CMakeFiles/weakPointer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/weakPointer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/weakPointer.dir/clean

CMakeFiles/weakPointer.dir/depend:
	cd "/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/agrsapan/Documents/C++ Tutorials" "/home/agrsapan/Documents/C++ Tutorials" "/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug" "/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug" "/home/agrsapan/Documents/C++ Tutorials/cmake-build-debug/CMakeFiles/weakPointer.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/weakPointer.dir/depend
