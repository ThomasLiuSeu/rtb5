# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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
include proto/CMakeFiles/order_pb.dir/depend.make

# Include the progress variables for this target.
include proto/CMakeFiles/order_pb.dir/progress.make

# Include the compile flags for this target's objects.
include proto/CMakeFiles/order_pb.dir/flags.make

proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o: proto/CMakeFiles/order_pb.dir/flags.make
proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o: proto/order.grpc.pb.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/src/cpp/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o"
	cd /home/qianwang/codebase/rtb5/src/cpp/proto && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/order_pb.dir/order.grpc.pb.cc.o -c /home/qianwang/codebase/rtb5/src/cpp/proto/order.grpc.pb.cc

proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/order_pb.dir/order.grpc.pb.cc.i"
	cd /home/qianwang/codebase/rtb5/src/cpp/proto && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qianwang/codebase/rtb5/src/cpp/proto/order.grpc.pb.cc > CMakeFiles/order_pb.dir/order.grpc.pb.cc.i

proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/order_pb.dir/order.grpc.pb.cc.s"
	cd /home/qianwang/codebase/rtb5/src/cpp/proto && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qianwang/codebase/rtb5/src/cpp/proto/order.grpc.pb.cc -o CMakeFiles/order_pb.dir/order.grpc.pb.cc.s

proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o.requires:
.PHONY : proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o.requires

proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o.provides: proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o.requires
	$(MAKE) -f proto/CMakeFiles/order_pb.dir/build.make proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o.provides.build
.PHONY : proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o.provides

proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o.provides.build: proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o

proto/CMakeFiles/order_pb.dir/order.pb.cc.o: proto/CMakeFiles/order_pb.dir/flags.make
proto/CMakeFiles/order_pb.dir/order.pb.cc.o: proto/order.pb.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/src/cpp/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object proto/CMakeFiles/order_pb.dir/order.pb.cc.o"
	cd /home/qianwang/codebase/rtb5/src/cpp/proto && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/order_pb.dir/order.pb.cc.o -c /home/qianwang/codebase/rtb5/src/cpp/proto/order.pb.cc

proto/CMakeFiles/order_pb.dir/order.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/order_pb.dir/order.pb.cc.i"
	cd /home/qianwang/codebase/rtb5/src/cpp/proto && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qianwang/codebase/rtb5/src/cpp/proto/order.pb.cc > CMakeFiles/order_pb.dir/order.pb.cc.i

proto/CMakeFiles/order_pb.dir/order.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/order_pb.dir/order.pb.cc.s"
	cd /home/qianwang/codebase/rtb5/src/cpp/proto && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qianwang/codebase/rtb5/src/cpp/proto/order.pb.cc -o CMakeFiles/order_pb.dir/order.pb.cc.s

proto/CMakeFiles/order_pb.dir/order.pb.cc.o.requires:
.PHONY : proto/CMakeFiles/order_pb.dir/order.pb.cc.o.requires

proto/CMakeFiles/order_pb.dir/order.pb.cc.o.provides: proto/CMakeFiles/order_pb.dir/order.pb.cc.o.requires
	$(MAKE) -f proto/CMakeFiles/order_pb.dir/build.make proto/CMakeFiles/order_pb.dir/order.pb.cc.o.provides.build
.PHONY : proto/CMakeFiles/order_pb.dir/order.pb.cc.o.provides

proto/CMakeFiles/order_pb.dir/order.pb.cc.o.provides.build: proto/CMakeFiles/order_pb.dir/order.pb.cc.o

proto/click.grpc.pb.h: proto/click.proto
proto/click.grpc.pb.h: proto/order.proto
proto/click.grpc.pb.h: proto/campaign.proto
proto/click.grpc.pb.h: proto/union.proto
proto/click.grpc.pb.h: proto/user.proto
proto/click.grpc.pb.h: proto/admin_server.proto
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/src/cpp/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating click.grpc.pb.h, click.grpc.pb.cc, order.grpc.pb.h, order.grpc.pb.cc, admin_server.grpc.pb.h, admin_server.grpc.pb.cc, proto"
	cd /home/qianwang/codebase/rtb5/src/cpp/proto && protoc -I . --grpc_out=. --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin click.proto order.proto campaign.proto union.proto user.proto admin_server.proto

proto/click.grpc.pb.cc: proto/click.grpc.pb.h

proto/order.grpc.pb.h: proto/click.grpc.pb.h

proto/order.grpc.pb.cc: proto/click.grpc.pb.h

proto/admin_server.grpc.pb.h: proto/click.grpc.pb.h

proto/admin_server.grpc.pb.cc: proto/click.grpc.pb.h

proto/proto: proto/click.grpc.pb.h

proto/click.pb.h: proto/click.proto
proto/click.pb.h: proto/order.proto
proto/click.pb.h: proto/campaign.proto
proto/click.pb.h: proto/union.proto
proto/click.pb.h: proto/user.proto
proto/click.pb.h: proto/admin_server.proto
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qianwang/codebase/rtb5/src/cpp/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating click.pb.h, click.pb.cc, order.pb.h, order.pb.cc, campaign.pb.h, campaign.pb.cc, union.pb.h, union.pb.cc, user.pb.h, user.pb.cc, admin_server.pb.h, admin_server.pb.cc, proto"
	cd /home/qianwang/codebase/rtb5/src/cpp/proto && protoc -I . --cpp_out . click.proto order.proto campaign.proto union.proto user.proto admin_server.proto

proto/click.pb.cc: proto/click.pb.h

proto/order.pb.h: proto/click.pb.h

proto/order.pb.cc: proto/click.pb.h

proto/campaign.pb.h: proto/click.pb.h

proto/campaign.pb.cc: proto/click.pb.h

proto/union.pb.h: proto/click.pb.h

proto/union.pb.cc: proto/click.pb.h

proto/user.pb.h: proto/click.pb.h

proto/user.pb.cc: proto/click.pb.h

proto/admin_server.pb.h: proto/click.pb.h

proto/admin_server.pb.cc: proto/click.pb.h

proto/proto: proto/click.pb.h

# Object files for target order_pb
order_pb_OBJECTS = \
"CMakeFiles/order_pb.dir/order.grpc.pb.cc.o" \
"CMakeFiles/order_pb.dir/order.pb.cc.o"

# External object files for target order_pb
order_pb_EXTERNAL_OBJECTS =

lib/liborder_pb.a: proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o
lib/liborder_pb.a: proto/CMakeFiles/order_pb.dir/order.pb.cc.o
lib/liborder_pb.a: proto/CMakeFiles/order_pb.dir/build.make
lib/liborder_pb.a: proto/CMakeFiles/order_pb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../lib/liborder_pb.a"
	cd /home/qianwang/codebase/rtb5/src/cpp/proto && $(CMAKE_COMMAND) -P CMakeFiles/order_pb.dir/cmake_clean_target.cmake
	cd /home/qianwang/codebase/rtb5/src/cpp/proto && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/order_pb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
proto/CMakeFiles/order_pb.dir/build: lib/liborder_pb.a
.PHONY : proto/CMakeFiles/order_pb.dir/build

proto/CMakeFiles/order_pb.dir/requires: proto/CMakeFiles/order_pb.dir/order.grpc.pb.cc.o.requires
proto/CMakeFiles/order_pb.dir/requires: proto/CMakeFiles/order_pb.dir/order.pb.cc.o.requires
.PHONY : proto/CMakeFiles/order_pb.dir/requires

proto/CMakeFiles/order_pb.dir/clean:
	cd /home/qianwang/codebase/rtb5/src/cpp/proto && $(CMAKE_COMMAND) -P CMakeFiles/order_pb.dir/cmake_clean.cmake
.PHONY : proto/CMakeFiles/order_pb.dir/clean

proto/CMakeFiles/order_pb.dir/depend: proto/click.grpc.pb.h
proto/CMakeFiles/order_pb.dir/depend: proto/click.grpc.pb.cc
proto/CMakeFiles/order_pb.dir/depend: proto/order.grpc.pb.h
proto/CMakeFiles/order_pb.dir/depend: proto/order.grpc.pb.cc
proto/CMakeFiles/order_pb.dir/depend: proto/admin_server.grpc.pb.h
proto/CMakeFiles/order_pb.dir/depend: proto/admin_server.grpc.pb.cc
proto/CMakeFiles/order_pb.dir/depend: proto/proto
proto/CMakeFiles/order_pb.dir/depend: proto/click.pb.h
proto/CMakeFiles/order_pb.dir/depend: proto/click.pb.cc
proto/CMakeFiles/order_pb.dir/depend: proto/order.pb.h
proto/CMakeFiles/order_pb.dir/depend: proto/order.pb.cc
proto/CMakeFiles/order_pb.dir/depend: proto/campaign.pb.h
proto/CMakeFiles/order_pb.dir/depend: proto/campaign.pb.cc
proto/CMakeFiles/order_pb.dir/depend: proto/union.pb.h
proto/CMakeFiles/order_pb.dir/depend: proto/union.pb.cc
proto/CMakeFiles/order_pb.dir/depend: proto/user.pb.h
proto/CMakeFiles/order_pb.dir/depend: proto/user.pb.cc
proto/CMakeFiles/order_pb.dir/depend: proto/admin_server.pb.h
proto/CMakeFiles/order_pb.dir/depend: proto/admin_server.pb.cc
proto/CMakeFiles/order_pb.dir/depend: proto/proto
	cd /home/qianwang/codebase/rtb5/src/cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/proto /home/qianwang/codebase/rtb5/src/cpp /home/qianwang/codebase/rtb5/src/cpp/proto /home/qianwang/codebase/rtb5/src/cpp/proto/CMakeFiles/order_pb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : proto/CMakeFiles/order_pb.dir/depend

