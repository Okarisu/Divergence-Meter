# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Toohka\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\221.5080.224\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Toohka\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\221.5080.224\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Toohka\Documents\.DEV\Divergence-Meter\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Toohka\Documents\.DEV\Divergence-Meter\src\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/nano_Wire.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/nano_Wire.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/nano_Wire.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nano_Wire.dir/flags.make

CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj: CMakeFiles/nano_Wire.dir/flags.make
CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj: C:/Program\ Files\ (x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp
CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj: CMakeFiles/nano_Wire.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Toohka\Documents\.DEV\Divergence-Meter\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj -MF CMakeFiles\nano_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp.obj.d -o CMakeFiles\nano_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp.obj -c "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp"

CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.i"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp" > CMakeFiles\nano_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp.i

CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.s"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp" -o CMakeFiles\nano_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\Wire.cpp.s

CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj: CMakeFiles/nano_Wire.dir/flags.make
CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj: C:/Program\ Files\ (x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c
CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj: CMakeFiles/nano_Wire.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Toohka\Documents\.DEV\Divergence-Meter\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj -MF CMakeFiles\nano_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c.obj.d -o CMakeFiles\nano_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c.obj -c "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c"

CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.i"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c" > CMakeFiles\nano_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c.i

CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.s"
	C:\PROGRA~2\Arduino\hardware\tools\avr\bin\avr-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c" -o CMakeFiles\nano_Wire.dir\C_\Program_Files_(x86)\Arduino\hardware\arduino\avr\libraries\Wire\src\utility\twi.c.s

# Object files for target nano_Wire
nano_Wire_OBJECTS = \
"CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj" \
"CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj"

# External object files for target nano_Wire
nano_Wire_EXTERNAL_OBJECTS =

libnano_Wire.a: CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/Wire.cpp.obj
libnano_Wire.a: CMakeFiles/nano_Wire.dir/C_/Program_Files_(x86)/Arduino/hardware/arduino/avr/libraries/Wire/src/utility/twi.c.obj
libnano_Wire.a: CMakeFiles/nano_Wire.dir/build.make
libnano_Wire.a: CMakeFiles/nano_Wire.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Toohka\Documents\.DEV\Divergence-Meter\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libnano_Wire.a"
	$(CMAKE_COMMAND) -P CMakeFiles\nano_Wire.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\nano_Wire.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nano_Wire.dir/build: libnano_Wire.a
.PHONY : CMakeFiles/nano_Wire.dir/build

CMakeFiles/nano_Wire.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\nano_Wire.dir\cmake_clean.cmake
.PHONY : CMakeFiles/nano_Wire.dir/clean

CMakeFiles/nano_Wire.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Toohka\Documents\.DEV\Divergence-Meter\src C:\Users\Toohka\Documents\.DEV\Divergence-Meter\src C:\Users\Toohka\Documents\.DEV\Divergence-Meter\src\cmake-build-debug C:\Users\Toohka\Documents\.DEV\Divergence-Meter\src\cmake-build-debug C:\Users\Toohka\Documents\.DEV\Divergence-Meter\src\cmake-build-debug\CMakeFiles\nano_Wire.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nano_Wire.dir/depend

