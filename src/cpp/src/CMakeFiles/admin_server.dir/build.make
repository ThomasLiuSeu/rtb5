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
include src/CMakeFiles/admin_server.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/admin_server.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/admin_server.dir/flags.make

src/CMakeFiles/admin_server.dir/admin_server.cc.o: src/CMakeFiles/admin_server.dir/flags.make
src/CMakeFiles/admin_server.dir/admin_server.cc.o: src/admin_server.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/src/cpp/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/admin_server.dir/admin_server.cc.o"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/admin_server.dir/admin_server.cc.o -c /home/qianwang/codebase/rtb5/src/cpp/src/admin_server.cc

src/CMakeFiles/admin_server.dir/admin_server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/admin_server.dir/admin_server.cc.i"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qianwang/codebase/rtb5/src/cpp/src/admin_server.cc > CMakeFiles/admin_server.dir/admin_server.cc.i

src/CMakeFiles/admin_server.dir/admin_server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/admin_server.dir/admin_server.cc.s"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qianwang/codebase/rtb5/src/cpp/src/admin_server.cc -o CMakeFiles/admin_server.dir/admin_server.cc.s

src/CMakeFiles/admin_server.dir/admin_server.cc.o.requires:
.PHONY : src/CMakeFiles/admin_server.dir/admin_server.cc.o.requires

src/CMakeFiles/admin_server.dir/admin_server.cc.o.provides: src/CMakeFiles/admin_server.dir/admin_server.cc.o.requires
	$(MAKE) -f src/CMakeFiles/admin_server.dir/build.make src/CMakeFiles/admin_server.dir/admin_server.cc.o.provides.build
.PHONY : src/CMakeFiles/admin_server.dir/admin_server.cc.o.provides

src/CMakeFiles/admin_server.dir/admin_server.cc.o.provides.build: src/CMakeFiles/admin_server.dir/admin_server.cc.o

# Object files for target admin_server
admin_server_OBJECTS = \
"CMakeFiles/admin_server.dir/admin_server.cc.o"

# External object files for target admin_server
admin_server_EXTERNAL_OBJECTS =

bin/admin_server: src/CMakeFiles/admin_server.dir/admin_server.cc.o
bin/admin_server: lib/libclick_pb.a
bin/admin_server: lib/libuser_pb.a
bin/admin_server: lib/libclick_processor.a
bin/admin_server: lib/libdatabase.a
bin/admin_server: lib/libclick_pb.a
bin/admin_server: lib/libuser_pb.a
bin/admin_server: lib/libcampaign_pb.a
bin/admin_server: lib/libunion_pb.a
bin/admin_server: src/CMakeFiles/admin_server.dir/build.make
bin/admin_server: src/CMakeFiles/admin_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/admin_server"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/admin_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/admin_server.dir/build: bin/admin_server
.PHONY : src/CMakeFiles/admin_server.dir/build

src/CMakeFiles/admin_server.dir/requires: src/CMakeFiles/admin_server.dir/admin_server.cc.o.requires
.PHONY : src/CMakeFiles/admin_server.dir/requires

src/CMakeFiles/admin_server.dir/clean:
	cd /home/qianwang/codebase/rtb5/src/cpp/src && $(CMAKE_COMMAND) -P CMakeFiles/admin_server.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/admin_server.dir/clean

src/CMakeFiles/admin_server.dir/depend:
	cd /home/qianwang/codebase/rtb5/src/cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src /home/qianwang/codebase/rtb5/src/cpp/src/CMakeFiles/admin_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/admin_server.dir/depend

