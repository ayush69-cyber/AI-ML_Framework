# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Ayush Khanal\AI-ML_Framework"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Ayush Khanal\AI-ML_Framework\build"

# Include any dependencies generated for this target.
include CMakeFiles/myproject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myproject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myproject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myproject.dir/flags.make

CMakeFiles/myproject.dir/codegen:
.PHONY : CMakeFiles/myproject.dir/codegen

CMakeFiles/myproject.dir/src/main.cpp.obj: CMakeFiles/myproject.dir/flags.make
CMakeFiles/myproject.dir/src/main.cpp.obj: CMakeFiles/myproject.dir/includes_CXX.rsp
CMakeFiles/myproject.dir/src/main.cpp.obj: C:/Users/Ayush\ Khanal/AI-ML_Framework/src/main.cpp
CMakeFiles/myproject.dir/src/main.cpp.obj: CMakeFiles/myproject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Ayush Khanal\AI-ML_Framework\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myproject.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myproject.dir/src/main.cpp.obj -MF CMakeFiles\myproject.dir\src\main.cpp.obj.d -o CMakeFiles\myproject.dir\src\main.cpp.obj -c "C:\Users\Ayush Khanal\AI-ML_Framework\src\main.cpp"

CMakeFiles/myproject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myproject.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Ayush Khanal\AI-ML_Framework\src\main.cpp" > CMakeFiles\myproject.dir\src\main.cpp.i

CMakeFiles/myproject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myproject.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Ayush Khanal\AI-ML_Framework\src\main.cpp" -o CMakeFiles\myproject.dir\src\main.cpp.s

CMakeFiles/myproject.dir/src/matrix.cpp.obj: CMakeFiles/myproject.dir/flags.make
CMakeFiles/myproject.dir/src/matrix.cpp.obj: CMakeFiles/myproject.dir/includes_CXX.rsp
CMakeFiles/myproject.dir/src/matrix.cpp.obj: C:/Users/Ayush\ Khanal/AI-ML_Framework/src/matrix.cpp
CMakeFiles/myproject.dir/src/matrix.cpp.obj: CMakeFiles/myproject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Ayush Khanal\AI-ML_Framework\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/myproject.dir/src/matrix.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myproject.dir/src/matrix.cpp.obj -MF CMakeFiles\myproject.dir\src\matrix.cpp.obj.d -o CMakeFiles\myproject.dir\src\matrix.cpp.obj -c "C:\Users\Ayush Khanal\AI-ML_Framework\src\matrix.cpp"

CMakeFiles/myproject.dir/src/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myproject.dir/src/matrix.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Ayush Khanal\AI-ML_Framework\src\matrix.cpp" > CMakeFiles\myproject.dir\src\matrix.cpp.i

CMakeFiles/myproject.dir/src/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myproject.dir/src/matrix.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Ayush Khanal\AI-ML_Framework\src\matrix.cpp" -o CMakeFiles\myproject.dir\src\matrix.cpp.s

# Object files for target myproject
myproject_OBJECTS = \
"CMakeFiles/myproject.dir/src/main.cpp.obj" \
"CMakeFiles/myproject.dir/src/matrix.cpp.obj"

# External object files for target myproject
myproject_EXTERNAL_OBJECTS =

myproject.exe: CMakeFiles/myproject.dir/src/main.cpp.obj
myproject.exe: CMakeFiles/myproject.dir/src/matrix.cpp.obj
myproject.exe: CMakeFiles/myproject.dir/build.make
myproject.exe: CMakeFiles/myproject.dir/linkLibs.rsp
myproject.exe: CMakeFiles/myproject.dir/objects1.rsp
myproject.exe: CMakeFiles/myproject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\Ayush Khanal\AI-ML_Framework\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable myproject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\myproject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myproject.dir/build: myproject.exe
.PHONY : CMakeFiles/myproject.dir/build

CMakeFiles/myproject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\myproject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/myproject.dir/clean

CMakeFiles/myproject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Ayush Khanal\AI-ML_Framework" "C:\Users\Ayush Khanal\AI-ML_Framework" "C:\Users\Ayush Khanal\AI-ML_Framework\build" "C:\Users\Ayush Khanal\AI-ML_Framework\build" "C:\Users\Ayush Khanal\AI-ML_Framework\build\CMakeFiles\myproject.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/myproject.dir/depend

