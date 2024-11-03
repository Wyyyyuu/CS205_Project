# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/资料/C++/opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/资料/C++/opencv/build

# Include any dependencies generated for this target.
include modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/compiler_depend.make

# Include the progress variables for this target.
include modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/progress.make

# Include the compile flags for this target's objects.
include modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o: ../opencv_contrib/modules/bgsegm/src/bgfg_gaussmix.cpp
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/资料/C++/opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o -MF CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o.d -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o -c /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_gaussmix.cpp

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.i"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_gaussmix.cpp > CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.i

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.s"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_gaussmix.cpp -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.s

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o: ../opencv_contrib/modules/bgsegm/src/bgfg_gmg.cpp
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/资料/C++/opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o -MF CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o.d -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o -c /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_gmg.cpp

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.i"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_gmg.cpp > CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.i

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.s"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_gmg.cpp -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.s

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o: ../opencv_contrib/modules/bgsegm/src/bgfg_gsoc.cpp
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/资料/C++/opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o -MF CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o.d -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o -c /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_gsoc.cpp

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.i"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_gsoc.cpp > CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.i

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.s"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_gsoc.cpp -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.s

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o: ../opencv_contrib/modules/bgsegm/src/bgfg_subcnt.cpp
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/资料/C++/opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o -MF CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o.d -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o -c /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_subcnt.cpp

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.i"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_subcnt.cpp > CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.i

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.s"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/bgfg_subcnt.cpp -o CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.s

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/flags.make
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o: ../opencv_contrib/modules/bgsegm/src/synthetic_seq.cpp
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/资料/C++/opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o -MF CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o.d -o CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o -c /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/synthetic_seq.cpp

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.i"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/synthetic_seq.cpp > CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.i

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.s"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm/src/synthetic_seq.cpp -o CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.s

# Object files for target opencv_bgsegm
opencv_bgsegm_OBJECTS = \
"CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o" \
"CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o" \
"CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o" \
"CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o" \
"CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o"

# External object files for target opencv_bgsegm
opencv_bgsegm_EXTERNAL_OBJECTS =

lib/libopencv_bgsegm.so.4.5.0: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gaussmix.cpp.o
lib/libopencv_bgsegm.so.4.5.0: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gmg.cpp.o
lib/libopencv_bgsegm.so.4.5.0: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_gsoc.cpp.o
lib/libopencv_bgsegm.so.4.5.0: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/bgfg_subcnt.cpp.o
lib/libopencv_bgsegm.so.4.5.0: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/src/synthetic_seq.cpp.o
lib/libopencv_bgsegm.so.4.5.0: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/build.make
lib/libopencv_bgsegm.so.4.5.0: lib/libopencv_video.so.4.5.0
lib/libopencv_bgsegm.so.4.5.0: 3rdparty/lib/libippiw.a
lib/libopencv_bgsegm.so.4.5.0: 3rdparty/ippicv/ippicv_lnx/icv/lib/intel64/libippicv.a
lib/libopencv_bgsegm.so.4.5.0: lib/libopencv_calib3d.so.4.5.0
lib/libopencv_bgsegm.so.4.5.0: lib/libopencv_features2d.so.4.5.0
lib/libopencv_bgsegm.so.4.5.0: lib/libopencv_flann.so.4.5.0
lib/libopencv_bgsegm.so.4.5.0: lib/libopencv_imgproc.so.4.5.0
lib/libopencv_bgsegm.so.4.5.0: lib/libopencv_core.so.4.5.0
lib/libopencv_bgsegm.so.4.5.0: modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/资料/C++/opencv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library ../../lib/libopencv_bgsegm.so"
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_bgsegm.dir/link.txt --verbose=$(VERBOSE)
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libopencv_bgsegm.so.4.5.0 ../../lib/libopencv_bgsegm.so.4.5 ../../lib/libopencv_bgsegm.so

lib/libopencv_bgsegm.so.4.5: lib/libopencv_bgsegm.so.4.5.0
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libopencv_bgsegm.so.4.5

lib/libopencv_bgsegm.so: lib/libopencv_bgsegm.so.4.5.0
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libopencv_bgsegm.so

# Rule to build all files generated by this target.
modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/build: lib/libopencv_bgsegm.so
.PHONY : modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/build

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/clean:
	cd /mnt/d/资料/C++/opencv/build/modules/bgsegm && $(CMAKE_COMMAND) -P CMakeFiles/opencv_bgsegm.dir/cmake_clean.cmake
.PHONY : modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/clean

modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/depend:
	cd /mnt/d/资料/C++/opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/资料/C++/opencv /mnt/d/资料/C++/opencv/opencv_contrib/modules/bgsegm /mnt/d/资料/C++/opencv/build /mnt/d/资料/C++/opencv/build/modules/bgsegm /mnt/d/资料/C++/opencv/build/modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/bgsegm/CMakeFiles/opencv_bgsegm.dir/depend

