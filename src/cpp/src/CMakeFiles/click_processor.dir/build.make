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
include src/CMakeFiles/click_processor.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/click_processor.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/click_processor.dir/flags.make

src/CMakeFiles/click_processor.dir/click_processor.cc.o: src/CMakeFiles/click_processor.dir/flags.make
src/CMakeFiles/click_processor.dir/click_processor.cc.o: src/click_processor.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/src/cpp/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/click_processor.dir/click_processor.cc.o"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/click_processor.dir/click_processor.cc.o -c /home/qianwang/codebase/rtb5/src/cpp/src/click_processor.cc

src/CMakeFiles/click_processor.dir/click_processor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/click_processor.dir/click_processor.cc.i"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qianwang/codebase/rtb5/src/cpp/src/click_processor.cc > CMakeFiles/click_processor.dir/click_processor.cc.i

src/CMakeFiles/click_processor.dir/click_processor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/click_processor.dir/click_processor.cc.s"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qianwang/codebase/rtb5/src/cpp/src/click_processor.cc -o CMakeFiles/click_processor.dir/click_processor.cc.s

src/CMakeFiles/click_processor.dir/click_processor.cc.o.requires:
.PHONY : src/CMakeFiles/click_processor.dir/click_processor.cc.o.requires

src/CMakeFiles/click_processor.dir/click_processor.cc.o.provides: src/CMakeFiles/click_processor.dir/click_processor.cc.o.requires
	$(MAKE) -f src/CMakeFiles/click_processor.dir/build.make src/CMakeFiles/click_processor.dir/click_processor.cc.o.provides.build
.PHONY : src/CMakeFiles/click_processor.dir/click_processor.cc.o.provides

src/CMakeFiles/click_processor.dir/click_processor.cc.o.provides.build: src/CMakeFiles/click_processor.dir/click_processor.cc.o

# Object files for target click_processor
click_processor_OBJECTS = \
"CMakeFiles/click_processor.dir/click_processor.cc.o"

# External object files for target click_processor
click_processor_EXTERNAL_OBJECTS =

lib/libclick_processor.a: src/CMakeFiles/click_processor.dir/click_processor.cc.o
lib/libclick_processor.a: src/CMakeFiles/click_processor.dir/build.make
lib/libclick_processor.a: src/CMakeFiles/click_processor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../lib/libclick_processor.a"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && $(CMAKE_COMMAND) -P CMakeFiles/click_processor.dir/cmake_clean_target.cmake
	cd /home/qianwang/codebase/rtb5/src/cpp/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/click_processor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/click_processor.dir/build: lib/libclick_processor.a
.PHONY : src/CMakeFiles/click_processor.dir/build

src/CMakeFiles/click_processor.dir/requires: src/CMakeFiles/click_processor.dir/click_processor.cc.o.requires
.PHONY : src/CMakeFiles/click_processor.dir/requires

src/CMakeFiles/click_processor.dir/clean:
	cd /home/qianwang/codebase/rtb5/src/cpp/src && $(CMAKE_COMMAND) -P CMakeFiles/click_processor.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/click_processor.dir/clean

src/CMakeFiles/click_processor.dir/depend:
	cd /home/qianwang/codebase/rtb5/src/cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src /home/qianwang/codebase/rtb5/src/cpp/src/CMakeFiles/click_processor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/click_processor.dir/depend

