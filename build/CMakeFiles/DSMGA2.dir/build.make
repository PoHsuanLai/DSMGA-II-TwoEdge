# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build

# Include any dependencies generated for this target.
include CMakeFiles/dsmga2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dsmga2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dsmga2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dsmga2.dir/flags.make

CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/python_binding/ga_wrapper.cpp
CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.o -MF CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.o.d -o CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/python_binding/ga_wrapper.cpp

CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/python_binding/ga_wrapper.cpp > CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.i

CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/python_binding/ga_wrapper.cpp -o CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.s

CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/chromosome.cpp
CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.o -MF CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.o.d -o CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/chromosome.cpp

CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/chromosome.cpp > CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.i

CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/chromosome.cpp -o CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.s

CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/dsmga2.cpp
CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.o -MF CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.o.d -o CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/dsmga2.cpp

CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/dsmga2.cpp > CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.i

CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/dsmga2.cpp -o CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.s

CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/fastcounting.cpp
CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.o -MF CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.o.d -o CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/fastcounting.cpp

CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/fastcounting.cpp > CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.i

CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/fastcounting.cpp -o CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.s

CMakeFiles/dsmga2.dir/src/core/global.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/core/global.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/global.cpp
CMakeFiles/dsmga2.dir/src/core/global.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/dsmga2.dir/src/core/global.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/core/global.cpp.o -MF CMakeFiles/dsmga2.dir/src/core/global.cpp.o.d -o CMakeFiles/dsmga2.dir/src/core/global.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/global.cpp

CMakeFiles/dsmga2.dir/src/core/global.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/core/global.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/global.cpp > CMakeFiles/dsmga2.dir/src/core/global.cpp.i

CMakeFiles/dsmga2.dir/src/core/global.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/core/global.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/global.cpp -o CMakeFiles/dsmga2.dir/src/core/global.cpp.s

CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/utils/mt19937ar.cpp
CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.o -MF CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.o.d -o CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/utils/mt19937ar.cpp

CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/utils/mt19937ar.cpp > CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.i

CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/utils/mt19937ar.cpp -o CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.s

CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/utils/myrand.cpp
CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.o -MF CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.o.d -o CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/utils/myrand.cpp

CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/utils/myrand.cpp > CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.i

CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/utils/myrand.cpp -o CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.s

CMakeFiles/dsmga2.dir/src/functions/spin.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/functions/spin.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/spin.cpp
CMakeFiles/dsmga2.dir/src/functions/spin.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/dsmga2.dir/src/functions/spin.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/functions/spin.cpp.o -MF CMakeFiles/dsmga2.dir/src/functions/spin.cpp.o.d -o CMakeFiles/dsmga2.dir/src/functions/spin.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/spin.cpp

CMakeFiles/dsmga2.dir/src/functions/spin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/functions/spin.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/spin.cpp > CMakeFiles/dsmga2.dir/src/functions/spin.cpp.i

CMakeFiles/dsmga2.dir/src/functions/spin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/functions/spin.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/spin.cpp -o CMakeFiles/dsmga2.dir/src/functions/spin.cpp.s

CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/nk-wa.cpp
CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.o -MF CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.o.d -o CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/nk-wa.cpp

CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/nk-wa.cpp > CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.i

CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/nk-wa.cpp -o CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.s

CMakeFiles/dsmga2.dir/src/functions/sat.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/functions/sat.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/sat.cpp
CMakeFiles/dsmga2.dir/src/functions/sat.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/dsmga2.dir/src/functions/sat.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/functions/sat.cpp.o -MF CMakeFiles/dsmga2.dir/src/functions/sat.cpp.o.d -o CMakeFiles/dsmga2.dir/src/functions/sat.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/sat.cpp

CMakeFiles/dsmga2.dir/src/functions/sat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/functions/sat.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/sat.cpp > CMakeFiles/dsmga2.dir/src/functions/sat.cpp.i

CMakeFiles/dsmga2.dir/src/functions/sat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/functions/sat.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/sat.cpp -o CMakeFiles/dsmga2.dir/src/functions/sat.cpp.s

CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/fitness_functions.cpp
CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.o -MF CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.o.d -o CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/fitness_functions.cpp

CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/fitness_functions.cpp > CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.i

CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/functions/fitness_functions.cpp -o CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.s

CMakeFiles/dsmga2.dir/src/core/sweep.cpp.o: CMakeFiles/dsmga2.dir/flags.make
CMakeFiles/dsmga2.dir/src/core/sweep.cpp.o: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/sweep.cpp
CMakeFiles/dsmga2.dir/src/core/sweep.cpp.o: CMakeFiles/dsmga2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/dsmga2.dir/src/core/sweep.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsmga2.dir/src/core/sweep.cpp.o -MF CMakeFiles/dsmga2.dir/src/core/sweep.cpp.o.d -o CMakeFiles/dsmga2.dir/src/core/sweep.cpp.o -c /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/sweep.cpp

CMakeFiles/dsmga2.dir/src/core/sweep.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsmga2.dir/src/core/sweep.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/sweep.cpp > CMakeFiles/dsmga2.dir/src/core/sweep.cpp.i

CMakeFiles/dsmga2.dir/src/core/sweep.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsmga2.dir/src/core/sweep.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/src/core/sweep.cpp -o CMakeFiles/dsmga2.dir/src/core/sweep.cpp.s

# Object files for target dsmga2
dsmga2_OBJECTS = \
"CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.o" \
"CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.o" \
"CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.o" \
"CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.o" \
"CMakeFiles/dsmga2.dir/src/core/global.cpp.o" \
"CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.o" \
"CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.o" \
"CMakeFiles/dsmga2.dir/src/functions/spin.cpp.o" \
"CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.o" \
"CMakeFiles/dsmga2.dir/src/functions/sat.cpp.o" \
"CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.o" \
"CMakeFiles/dsmga2.dir/src/core/sweep.cpp.o"

# External object files for target dsmga2
dsmga2_EXTERNAL_OBJECTS =

/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/python_binding/ga_wrapper.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/core/chromosome.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/core/dsmga2.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/core/fastcounting.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/core/global.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/utils/mt19937ar.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/utils/myrand.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/functions/spin.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/functions/nk-wa.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/functions/sat.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/functions/fitness_functions.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/src/core/sweep.cpp.o
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/build.make
/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so: CMakeFiles/dsmga2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX shared module /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dsmga2.dir/link.txt --verbose=$(VERBOSE)
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip -x /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so

# Rule to build all files generated by this target.
CMakeFiles/dsmga2.dir/build: /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/bin/dsmga2.cpython-39-darwin.so
.PHONY : CMakeFiles/dsmga2.dir/build

CMakeFiles/dsmga2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dsmga2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dsmga2.dir/clean

CMakeFiles/dsmga2.dir/depend:
	cd /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build /Users/santaclaus/Documents/GA/DSMGA-II-TwoEdge/build/CMakeFiles/dsmga2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/dsmga2.dir/depend

