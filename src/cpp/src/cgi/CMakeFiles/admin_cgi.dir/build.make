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
include src/cgi/CMakeFiles/admin_cgi.dir/depend.make

# Include the progress variables for this target.
include src/cgi/CMakeFiles/admin_cgi.dir/progress.make

# Include the compile flags for this target's objects.
include src/cgi/CMakeFiles/admin_cgi.dir/flags.make

src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o: src/cgi/CMakeFiles/admin_cgi.dir/flags.make
src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o: src/cgi/admin_cgi.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/src/cpp/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o"
	cd /home/qianwang/codebase/rtb5/src/cpp/src/cgi && gcc   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/admin_cgi.dir/admin_cgi.cc.o -c /home/qianwang/codebase/rtb5/src/cpp/src/cgi/admin_cgi.cc

src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/admin_cgi.dir/admin_cgi.cc.i"
	cd /home/qianwang/codebase/rtb5/src/cpp/src/cgi && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qianwang/codebase/rtb5/src/cpp/src/cgi/admin_cgi.cc > CMakeFiles/admin_cgi.dir/admin_cgi.cc.i

src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/admin_cgi.dir/admin_cgi.cc.s"
	cd /home/qianwang/codebase/rtb5/src/cpp/src/cgi && gcc  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qianwang/codebase/rtb5/src/cpp/src/cgi/admin_cgi.cc -o CMakeFiles/admin_cgi.dir/admin_cgi.cc.s

src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o.requires:
.PHONY : src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o.requires

src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o.provides: src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o.requires
	$(MAKE) -f src/cgi/CMakeFiles/admin_cgi.dir/build.make src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o.provides.build
.PHONY : src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o.provides

src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o.provides.build: src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o

# Object files for target admin_cgi
admin_cgi_OBJECTS = \
"CMakeFiles/admin_cgi.dir/admin_cgi.cc.o"

# External object files for target admin_cgi
admin_cgi_EXTERNAL_OBJECTS =

bin/admin_cgi: src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o
bin/admin_cgi: lib/libadmin_server_pb.a
bin/admin_cgi: lib/libencoding.a
bin/admin_cgi: lib/libclick_pb.a
bin/admin_cgi: lib/libuser_pb.a
bin/admin_cgi: lib/libunion_pb.a
bin/admin_cgi: lib/libcampaign_pb.a
bin/admin_cgi: lib/libstring_utility.a
bin/admin_cgi: src/cgi/CMakeFiles/admin_cgi.dir/build.make
bin/admin_cgi: src/cgi/CMakeFiles/admin_cgi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/admin_cgi"
	cd /home/qianwang/codebase/rtb5/src/cpp/src/cgi && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/admin_cgi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/cgi/CMakeFiles/admin_cgi.dir/build: bin/admin_cgi
.PHONY : src/cgi/CMakeFiles/admin_cgi.dir/build

src/cgi/CMakeFiles/admin_cgi.dir/requires: src/cgi/CMakeFiles/admin_cgi.dir/admin_cgi.cc.o.requires
.PHONY : src/cgi/CMakeFiles/admin_cgi.dir/requires

src/cgi/CMakeFiles/admin_cgi.dir/clean:
	cd /home/qianwang/codebase/rtb5/src/cpp/src/cgi && $(CMAKE_COMMAND) -P CMakeFiles/admin_cgi.dir/cmake_clean.cmake
.PHONY : src/cgi/CMakeFiles/admin_cgi.dir/clean

src/cgi/CMakeFiles/admin_cgi.dir/depend:
	cd /home/qianwang/codebase/rtb5/src/cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src/cgi /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/src/cgi /home/qianwang/codebase/rtb5/src/cpp/src/cgi/CMakeFiles/admin_cgi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/cgi/CMakeFiles/admin_cgi.dir/depend

