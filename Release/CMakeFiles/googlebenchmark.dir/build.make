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
CMAKE_SOURCE_DIR = /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release

# Utility rule file for googlebenchmark.

# Include the progress variables for this target.
include CMakeFiles/googlebenchmark.dir/progress.make

CMakeFiles/googlebenchmark: CMakeFiles/googlebenchmark-complete


CMakeFiles/googlebenchmark-complete: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-install
CMakeFiles/googlebenchmark-complete: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-mkdir
CMakeFiles/googlebenchmark-complete: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-download
CMakeFiles/googlebenchmark-complete: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-update
CMakeFiles/googlebenchmark-complete: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-patch
CMakeFiles/googlebenchmark-complete: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-configure
CMakeFiles/googlebenchmark-complete: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-build
CMakeFiles/googlebenchmark-complete: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'googlebenchmark'"
	/opt/local/bin/cmake -E make_directory /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/CMakeFiles
	/opt/local/bin/cmake -E touch /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/CMakeFiles/googlebenchmark-complete
	/opt/local/bin/cmake -E touch /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-done

googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-install: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing install step for 'googlebenchmark'"
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-build && $(MAKE) install
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-build && /opt/local/bin/cmake -E touch /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-install

googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'googlebenchmark'"
	/opt/local/bin/cmake -E make_directory /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark
	/opt/local/bin/cmake -E make_directory /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-build
	/opt/local/bin/cmake -E make_directory /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix
	/opt/local/bin/cmake -E make_directory /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/tmp
	/opt/local/bin/cmake -E make_directory /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp
	/opt/local/bin/cmake -E make_directory /Users/yg9418/.cmake-downloads
	/opt/local/bin/cmake -E make_directory /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp
	/opt/local/bin/cmake -E touch /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-mkdir

googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-download: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-urlinfo.txt
googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-download: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (download, verify and extract) for 'googlebenchmark'"
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src && /opt/local/bin/cmake -P /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp/download-googlebenchmark.cmake
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src && /opt/local/bin/cmake -P /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp/verify-googlebenchmark.cmake
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src && /opt/local/bin/cmake -P /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp/extract-googlebenchmark.cmake
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src && /opt/local/bin/cmake -E touch /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-download

googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-update: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No update step for 'googlebenchmark'"
	/opt/local/bin/cmake -E echo_append
	/opt/local/bin/cmake -E touch /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-update

googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-patch: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'googlebenchmark'"
	/opt/local/bin/cmake -E echo_append
	/opt/local/bin/cmake -E touch /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-patch

googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-configure: googlebenchmark-prefix/tmp/googlebenchmark-cfgcmd.txt
googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-configure: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-update
googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-configure: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing configure step for 'googlebenchmark'"
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-build && /opt/local/bin/cmake -DCMAKE_INSTALL_PREFIX=/Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/deps -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON -DBENCHMARK_ENABLE_GTEST_TESTS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=/Library/Developer/CommandLineTools/usr/bin/c++ "-GUnix Makefiles" /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-build && /opt/local/bin/cmake -E touch /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-configure

googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-build: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Performing build step for 'googlebenchmark'"
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-build && $(MAKE)
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-build && /opt/local/bin/cmake -E touch /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-build

googlebenchmark: CMakeFiles/googlebenchmark
googlebenchmark: CMakeFiles/googlebenchmark-complete
googlebenchmark: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-install
googlebenchmark: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-mkdir
googlebenchmark: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-download
googlebenchmark: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-update
googlebenchmark: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-patch
googlebenchmark: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-configure
googlebenchmark: googlebenchmark-prefix/src/googlebenchmark-stamp/googlebenchmark-build
googlebenchmark: CMakeFiles/googlebenchmark.dir/build.make

.PHONY : googlebenchmark

# Rule to build all files generated by this target.
CMakeFiles/googlebenchmark.dir/build: googlebenchmark

.PHONY : CMakeFiles/googlebenchmark.dir/build

CMakeFiles/googlebenchmark.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/googlebenchmark.dir/cmake_clean.cmake
.PHONY : CMakeFiles/googlebenchmark.dir/clean

CMakeFiles/googlebenchmark.dir/depend:
	cd /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72 /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72 /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release /Users/yg9418/Desktop/Year3/Advanced_Databases/shapecount_72/Release/CMakeFiles/googlebenchmark.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/googlebenchmark.dir/depend

