# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "F:\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/entrega_2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/entrega_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/entrega_2.dir/flags.make

CMakeFiles/entrega_2.dir/main.cpp.obj: CMakeFiles/entrega_2.dir/flags.make
CMakeFiles/entrega_2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/entrega_2.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\entrega_2.dir\main.cpp.obj -c "C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2\main.cpp"

CMakeFiles/entrega_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entrega_2.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2\main.cpp" > CMakeFiles\entrega_2.dir\main.cpp.i

CMakeFiles/entrega_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entrega_2.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2\main.cpp" -o CMakeFiles\entrega_2.dir\main.cpp.s

# Object files for target entrega_2
entrega_2_OBJECTS = \
"CMakeFiles/entrega_2.dir/main.cpp.obj"

# External object files for target entrega_2
entrega_2_EXTERNAL_OBJECTS =

entrega_2.exe: CMakeFiles/entrega_2.dir/main.cpp.obj
entrega_2.exe: CMakeFiles/entrega_2.dir/build.make
entrega_2.exe: CMakeFiles/entrega_2.dir/linklibs.rsp
entrega_2.exe: CMakeFiles/entrega_2.dir/objects1.rsp
entrega_2.exe: CMakeFiles/entrega_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable entrega_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\entrega_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/entrega_2.dir/build: entrega_2.exe
.PHONY : CMakeFiles/entrega_2.dir/build

CMakeFiles/entrega_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\entrega_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/entrega_2.dir/clean

CMakeFiles/entrega_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2" "C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2" "C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2\cmake-build-debug" "C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2\cmake-build-debug" "C:\Users\USUARIO\Desktop\algo1nuevo\entrega 2\cmake-build-debug\CMakeFiles\entrega_2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/entrega_2.dir/depend

