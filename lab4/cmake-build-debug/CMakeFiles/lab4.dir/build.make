# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/dani/Desktop/sources/clion-2018.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dani/Desktop/sources/clion-2018.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab4.dir/flags.make

CMakeFiles/lab4.dir/main.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab4.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4.dir/main.cpp.o -c /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/main.cpp

CMakeFiles/lab4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/main.cpp > CMakeFiles/lab4.dir/main.cpp.i

CMakeFiles/lab4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/main.cpp -o CMakeFiles/lab4.dir/main.cpp.s

CMakeFiles/lab4.dir/ExtendedTest.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/ExtendedTest.cpp.o: ../ExtendedTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab4.dir/ExtendedTest.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4.dir/ExtendedTest.cpp.o -c /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/ExtendedTest.cpp

CMakeFiles/lab4.dir/ExtendedTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.dir/ExtendedTest.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/ExtendedTest.cpp > CMakeFiles/lab4.dir/ExtendedTest.cpp.i

CMakeFiles/lab4.dir/ExtendedTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/ExtendedTest.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/ExtendedTest.cpp -o CMakeFiles/lab4.dir/ExtendedTest.cpp.s

CMakeFiles/lab4.dir/ShortTest.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/ShortTest.cpp.o: ../ShortTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab4.dir/ShortTest.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4.dir/ShortTest.cpp.o -c /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/ShortTest.cpp

CMakeFiles/lab4.dir/ShortTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.dir/ShortTest.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/ShortTest.cpp > CMakeFiles/lab4.dir/ShortTest.cpp.i

CMakeFiles/lab4.dir/ShortTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/ShortTest.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/ShortTest.cpp -o CMakeFiles/lab4.dir/ShortTest.cpp.s

CMakeFiles/lab4.dir/LinkedList.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/LinkedList.cpp.o: ../LinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab4.dir/LinkedList.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4.dir/LinkedList.cpp.o -c /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/LinkedList.cpp

CMakeFiles/lab4.dir/LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.dir/LinkedList.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/LinkedList.cpp > CMakeFiles/lab4.dir/LinkedList.cpp.i

CMakeFiles/lab4.dir/LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/LinkedList.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/LinkedList.cpp -o CMakeFiles/lab4.dir/LinkedList.cpp.s

CMakeFiles/lab4.dir/Bag.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/Bag.cpp.o: ../Bag.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lab4.dir/Bag.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4.dir/Bag.cpp.o -c /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/Bag.cpp

CMakeFiles/lab4.dir/Bag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.dir/Bag.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/Bag.cpp > CMakeFiles/lab4.dir/Bag.cpp.i

CMakeFiles/lab4.dir/Bag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/Bag.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/Bag.cpp -o CMakeFiles/lab4.dir/Bag.cpp.s

CMakeFiles/lab4.dir/BagIterator.cpp.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/BagIterator.cpp.o: ../BagIterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lab4.dir/BagIterator.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab4.dir/BagIterator.cpp.o -c /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/BagIterator.cpp

CMakeFiles/lab4.dir/BagIterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab4.dir/BagIterator.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/BagIterator.cpp > CMakeFiles/lab4.dir/BagIterator.cpp.i

CMakeFiles/lab4.dir/BagIterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab4.dir/BagIterator.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/BagIterator.cpp -o CMakeFiles/lab4.dir/BagIterator.cpp.s

# Object files for target lab4
lab4_OBJECTS = \
"CMakeFiles/lab4.dir/main.cpp.o" \
"CMakeFiles/lab4.dir/ExtendedTest.cpp.o" \
"CMakeFiles/lab4.dir/ShortTest.cpp.o" \
"CMakeFiles/lab4.dir/LinkedList.cpp.o" \
"CMakeFiles/lab4.dir/Bag.cpp.o" \
"CMakeFiles/lab4.dir/BagIterator.cpp.o"

# External object files for target lab4
lab4_EXTERNAL_OBJECTS =

lab4: CMakeFiles/lab4.dir/main.cpp.o
lab4: CMakeFiles/lab4.dir/ExtendedTest.cpp.o
lab4: CMakeFiles/lab4.dir/ShortTest.cpp.o
lab4: CMakeFiles/lab4.dir/LinkedList.cpp.o
lab4: CMakeFiles/lab4.dir/Bag.cpp.o
lab4: CMakeFiles/lab4.dir/BagIterator.cpp.o
lab4: CMakeFiles/lab4.dir/build.make
lab4: CMakeFiles/lab4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable lab4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab4.dir/build: lab4

.PHONY : CMakeFiles/lab4.dir/build

CMakeFiles/lab4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab4.dir/clean

CMakeFiles/lab4.dir/depend:
	cd /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4 /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4 /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug /home/dani/Desktop/code/faculta/an1/sem2/DSA/lab4/cmake-build-debug/CMakeFiles/lab4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab4.dir/depend

