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
include src/cgi/CMakeFiles/click_cgi.dir/depend.make

# Include the progress variables for this target.
include src/cgi/CMakeFiles/click_cgi.dir/progress.make

# Include the compile flags for this target's objects.
include src/cgi/CMakeFiles/click_cgi.dir/flags.make

src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o: src/cgi/CMakeFiles/click_cgi.dir/flags.make
src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o: src/cgi/click_cgi.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/src/cpp/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o"
	cd /home/qianwang/codebase/rtb5/src/cpp/src/cgi && gcc   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/click_cgi.dir/click_cgi.cc.o -c /home/qianwang/codebase/rtb5/src/cpp/src/cgi/click_cgi.cc

src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/click_cgi.dir/click_cgi.cc.i"
	cd /home/qianwang/codebase/rtb5/src/cpp/src/cgi && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qianwang/codebase/rtb5/src/cpp/src/cgi/click_cgi.cc > CMakeFiles/click_cgi.dir/click_cgi.cc.i

src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/click_cgi.dir/click_cgi.cc.s"
	cd /home/qianwang/codebase/rtb5/src/cpp/src/cgi && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qianwang/codebase/rtb5/src/cpp/src/cgi/click_cgi.cc -o CMakeFiles/click_cgi.dir/click_cgi.cc.s

src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o.requires:
.PHONY : src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o.requires

src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o.provides: src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o.requires
	$(MAKE) -f src/cgi/CMakeFiles/click_cgi.dir/build.make src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o.provides.build
.PHONY : src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o.provides

src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o.provides.build: src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o

# Object files for target click_cgi
click_cgi_OBJECTS = \
"CMakeFiles/click_cgi.dir/click_cgi.cc.o"

# External object files for target click_cgi
click_cgi_EXTERNAL_OBJECTS =

bin/click_cgi: src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o
bin/click_cgi: lib/libclick_pb.a
bin/click_cgi: src/cgi/CMakeFiles/click_cgi.dir/build.make
bin/click_cgi: src/cgi/CMakeFiles/click_cgi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/click_cgi"
	cd /home/qianwang/codebase/rtb5/src/cpp/src/cgi && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/click_cgi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/cgi/CMakeFiles/click_cgi.dir/build: bin/click_cgi
.PHONY : src/cgi/CMakeFiles/click_cgi.dir/build

src/cgi/CMakeFiles/click_cgi.dir/requires: src/cgi/CMakeFiles/click_cgi.dir/click_cgi.cc.o.requires
.PHONY : src/cgi/CMakeFiles/click_cgi.dir/requires

src/cgi/CMakeFiles/click_cgi.dir/clean:
	cd /home/qianwang/codebase/rtb5/src/cpp/src/cgi && $(CMAKE_COMMAND) -P CMakeFiles/click_cgi.dir/cmake_clean.cmake
.PHONY : src/cgi/CMakeFiles/click_cgi.dir/clean

src/cgi/CMakeFiles/click_cgi.dir/depend:
	cd /home/qianwang/codebase/rtb5/src/cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src/cgi /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src/cgi /home/qianwang/codebase/rtb5/src/cpp/src/cgi/CMakeFiles/click_cgi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/cgi/CMakeFiles/click_cgi.dir/depend

