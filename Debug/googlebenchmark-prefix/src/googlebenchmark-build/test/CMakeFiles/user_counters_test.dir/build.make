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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build

# Include any dependencies generated for this target.
include test/CMakeFiles/user_counters_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/user_counters_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/user_counters_test.dir/flags.make

test/CMakeFiles/user_counters_test.dir/user_counters_test.cc.o: test/CMakeFiles/user_counters_test.dir/flags.make
test/CMakeFiles/user_counters_test.dir/user_counters_test.cc.o: /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark/test/user_counters_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/user_counters_test.dir/user_counters_test.cc.o"
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/user_counters_test.dir/user_counters_test.cc.o -c /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark/test/user_counters_test.cc

test/CMakeFiles/user_counters_test.dir/user_counters_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/user_counters_test.dir/user_counters_test.cc.i"
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark/test/user_counters_test.cc > CMakeFiles/user_counters_test.dir/user_counters_test.cc.i

test/CMakeFiles/user_counters_test.dir/user_counters_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/user_counters_test.dir/user_counters_test.cc.s"
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark/test/user_counters_test.cc -o CMakeFiles/user_counters_test.dir/user_counters_test.cc.s

# Object files for target user_counters_test
user_counters_test_OBJECTS = \
"CMakeFiles/user_counters_test.dir/user_counters_test.cc.o"

# External object files for target user_counters_test
user_counters_test_EXTERNAL_OBJECTS =

test/user_counters_test: test/CMakeFiles/user_counters_test.dir/user_counters_test.cc.o
test/user_counters_test: test/CMakeFiles/user_counters_test.dir/build.make
test/user_counters_test: test/liboutput_test_helper.a
test/user_counters_test: src/libbenchmark.a
test/user_counters_test: test/CMakeFiles/user_counters_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable user_counters_test"
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/user_counters_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/user_counters_test.dir/build: test/user_counters_test

.PHONY : test/CMakeFiles/user_counters_test.dir/build

test/CMakeFiles/user_counters_test.dir/clean:
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build/test && $(CMAKE_COMMAND) -P CMakeFiles/user_counters_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/user_counters_test.dir/clean

test/CMakeFiles/user_counters_test.dir/depend:
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark/test /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build/test /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Debug/googlebenchmark-prefix/src/googlebenchmark-build/test/CMakeFiles/user_counters_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/user_counters_test.dir/depend

