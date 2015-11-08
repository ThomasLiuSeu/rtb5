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
include src/CMakeFiles/order_update.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/order_update.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/order_update.dir/flags.make

src/CMakeFiles/order_update.dir/order_update.cc.o: src/CMakeFiles/order_update.dir/flags.make
src/CMakeFiles/order_update.dir/order_update.cc.o: src/order_update.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/src/cpp/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/order_update.dir/order_update.cc.o"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/order_update.dir/order_update.cc.o -c /home/qianwang/codebase/rtb5/src/cpp/src/order_update.cc

src/CMakeFiles/order_update.dir/order_update.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/order_update.dir/order_update.cc.i"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qianwang/codebase/rtb5/src/cpp/src/order_update.cc > CMakeFiles/order_update.dir/order_update.cc.i

src/CMakeFiles/order_update.dir/order_update.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/order_update.dir/order_update.cc.s"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qianwang/codebase/rtb5/src/cpp/src/order_update.cc -o CMakeFiles/order_update.dir/order_update.cc.s

src/CMakeFiles/order_update.dir/order_update.cc.o.requires:
.PHONY : src/CMakeFiles/order_update.dir/order_update.cc.o.requires

src/CMakeFiles/order_update.dir/order_update.cc.o.provides: src/CMakeFiles/order_update.dir/order_update.cc.o.requires
	$(MAKE) -f src/CMakeFiles/order_update.dir/build.make src/CMakeFiles/order_update.dir/order_update.cc.o.provides.build
.PHONY : src/CMakeFiles/order_update.dir/order_update.cc.o.provides

src/CMakeFiles/order_update.dir/order_update.cc.o.provides.build: src/CMakeFiles/order_update.dir/order_update.cc.o

# Object files for target order_update
order_update_OBJECTS = \
"CMakeFiles/order_update.dir/order_update.cc.o"

# External object files for target order_update
order_update_EXTERNAL_OBJECTS =

bin/order_update: src/CMakeFiles/order_update.dir/order_update.cc.o
bin/order_update: lib/liborder_update_processor.a
bin/order_update: lib/libdatabase.a
bin/order_update: lib/libhaitao55_order_update_functor.a
bin/order_update: lib/libuser_pb.a
bin/order_update: lib/libviglink_order_update_functor.a
bin/order_update: lib/libhttp_client.a
bin/order_update: lib/libcampaign_pb.a
bin/order_update: lib/libunion_pb.a
bin/order_update: lib/liborder_pb.a
bin/order_update: lib/libclick_pb.a
bin/order_update: src/CMakeFiles/order_update.dir/build.make
bin/order_update: src/CMakeFiles/order_update.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/order_update"
	cd /home/qianwang/codebase/rtb5/src/cpp/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/order_update.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/order_update.dir/build: bin/order_update
.PHONY : src/CMakeFiles/order_update.dir/build

src/CMakeFiles/order_update.dir/requires: src/CMakeFiles/order_update.dir/order_update.cc.o.requires
.PHONY : src/CMakeFiles/order_update.dir/requires

src/CMakeFiles/order_update.dir/clean:
	cd /home/qianwang/codebase/rtb5/src/cpp/src && $(CMAKE_COMMAND) -P CMakeFiles/order_update.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/order_update.dir/clean

src/CMakeFiles/order_update.dir/depend:
	cd /home/qianwang/codebase/rtb5/src/cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src /home/qianwang/codebase/rtb5/src/cpp/src/CMakeFiles/order_update.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/order_update.dir/depend

