# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qianwang/codebase/rtb5/src/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qianwang/codebase/rtb5/src/cpp

# Include any dependencies generated for this target.
include src/CMakeFiles/database.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/database.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/database.dir/flags.make

src/CMakeFiles/database.dir/database.cc.o: src/CMakeFiles/database.dir/flags.make
src/CMakeFiles/database.dir/database.cc.o: src/database.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/src/cpp/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/database.dir/database.cc.o"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/database.dir/database.cc.o -c /home/qianwang/codebase/rtb5/src/cpp/src/database.cc

src/CMakeFiles/database.dir/database.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/database.dir/database.cc.i"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qianwang/codebase/rtb5/src/cpp/src/database.cc > CMakeFiles/database.dir/database.cc.i

src/CMakeFiles/database.dir/database.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/database.dir/database.cc.s"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qianwang/codebase/rtb5/src/cpp/src/database.cc -o CMakeFiles/database.dir/database.cc.s

src/CMakeFiles/database.dir/database.cc.o.requires:
.PHONY : src/CMakeFiles/database.dir/database.cc.o.requires

src/CMakeFiles/database.dir/database.cc.o.provides: src/CMakeFiles/database.dir/database.cc.o.requires
	$(MAKE) -f src/CMakeFiles/database.dir/build.make src/CMakeFiles/database.dir/database.cc.o.provides.build
.PHONY : src/CMakeFiles/database.dir/database.cc.o.provides

src/CMakeFiles/database.dir/database.cc.o.provides.build: src/CMakeFiles/database.dir/database.cc.o

# Object files for target database
database_OBJECTS = \
"CMakeFiles/database.dir/database.cc.o"

# External object files for target database
database_EXTERNAL_OBJECTS =

lib/libdatabase.a: src/CMakeFiles/database.dir/database.cc.o
lib/libdatabase.a: src/CMakeFiles/database.dir/build.make
lib/libdatabase.a: src/CMakeFiles/database.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../lib/libdatabase.a"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && $(CMAKE_COMMAND) -P CMakeFiles/database.dir/cmake_clean_target.cmake
	cd /home/qianwang/codebase/rtb5/src/cpp/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/database.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/database.dir/build: lib/libdatabase.a
.PHONY : src/CMakeFiles/database.dir/build

src/CMakeFiles/database.dir/requires: src/CMakeFiles/database.dir/database.cc.o.requires
.PHONY : src/CMakeFiles/database.dir/requires

src/CMakeFiles/database.dir/clean:
	cd /home/qianwang/codebase/rtb5/src/cpp/src && $(CMAKE_COMMAND) -P CMakeFiles/database.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/database.dir/clean

src/CMakeFiles/database.dir/depend:
	cd /home/qianwang/codebase/rtb5/src/cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src /home/qianwang/codebase/rtb5/src/cpp/src/CMakeFiles/database.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/database.dir/depend

