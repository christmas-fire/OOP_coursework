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
CMAKE_SOURCE_DIR = /home/christmas_fire/OOP_coursework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christmas_fire/OOP_coursework/build

# Include any dependencies generated for this target.
include CMakeFiles/MealDatabase.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MealDatabase.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MealDatabase.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MealDatabase.dir/flags.make

CMakeFiles/MealDatabase.dir/main.cpp.o: CMakeFiles/MealDatabase.dir/flags.make
CMakeFiles/MealDatabase.dir/main.cpp.o: ../main.cpp
CMakeFiles/MealDatabase.dir/main.cpp.o: CMakeFiles/MealDatabase.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christmas_fire/OOP_coursework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MealDatabase.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MealDatabase.dir/main.cpp.o -MF CMakeFiles/MealDatabase.dir/main.cpp.o.d -o CMakeFiles/MealDatabase.dir/main.cpp.o -c /home/christmas_fire/OOP_coursework/main.cpp

CMakeFiles/MealDatabase.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MealDatabase.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christmas_fire/OOP_coursework/main.cpp > CMakeFiles/MealDatabase.dir/main.cpp.i

CMakeFiles/MealDatabase.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MealDatabase.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christmas_fire/OOP_coursework/main.cpp -o CMakeFiles/MealDatabase.dir/main.cpp.s

CMakeFiles/MealDatabase.dir/database.cpp.o: CMakeFiles/MealDatabase.dir/flags.make
CMakeFiles/MealDatabase.dir/database.cpp.o: ../database.cpp
CMakeFiles/MealDatabase.dir/database.cpp.o: CMakeFiles/MealDatabase.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christmas_fire/OOP_coursework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MealDatabase.dir/database.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MealDatabase.dir/database.cpp.o -MF CMakeFiles/MealDatabase.dir/database.cpp.o.d -o CMakeFiles/MealDatabase.dir/database.cpp.o -c /home/christmas_fire/OOP_coursework/database.cpp

CMakeFiles/MealDatabase.dir/database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MealDatabase.dir/database.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christmas_fire/OOP_coursework/database.cpp > CMakeFiles/MealDatabase.dir/database.cpp.i

CMakeFiles/MealDatabase.dir/database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MealDatabase.dir/database.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christmas_fire/OOP_coursework/database.cpp -o CMakeFiles/MealDatabase.dir/database.cpp.s

CMakeFiles/MealDatabase.dir/meal.cpp.o: CMakeFiles/MealDatabase.dir/flags.make
CMakeFiles/MealDatabase.dir/meal.cpp.o: ../meal.cpp
CMakeFiles/MealDatabase.dir/meal.cpp.o: CMakeFiles/MealDatabase.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christmas_fire/OOP_coursework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MealDatabase.dir/meal.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MealDatabase.dir/meal.cpp.o -MF CMakeFiles/MealDatabase.dir/meal.cpp.o.d -o CMakeFiles/MealDatabase.dir/meal.cpp.o -c /home/christmas_fire/OOP_coursework/meal.cpp

CMakeFiles/MealDatabase.dir/meal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MealDatabase.dir/meal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christmas_fire/OOP_coursework/meal.cpp > CMakeFiles/MealDatabase.dir/meal.cpp.i

CMakeFiles/MealDatabase.dir/meal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MealDatabase.dir/meal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christmas_fire/OOP_coursework/meal.cpp -o CMakeFiles/MealDatabase.dir/meal.cpp.s

# Object files for target MealDatabase
MealDatabase_OBJECTS = \
"CMakeFiles/MealDatabase.dir/main.cpp.o" \
"CMakeFiles/MealDatabase.dir/database.cpp.o" \
"CMakeFiles/MealDatabase.dir/meal.cpp.o"

# External object files for target MealDatabase
MealDatabase_EXTERNAL_OBJECTS =

MealDatabase: CMakeFiles/MealDatabase.dir/main.cpp.o
MealDatabase: CMakeFiles/MealDatabase.dir/database.cpp.o
MealDatabase: CMakeFiles/MealDatabase.dir/meal.cpp.o
MealDatabase: CMakeFiles/MealDatabase.dir/build.make
MealDatabase: /usr/lib/x86_64-linux-gnu/libsqlite3.so
MealDatabase: CMakeFiles/MealDatabase.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christmas_fire/OOP_coursework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable MealDatabase"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MealDatabase.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MealDatabase.dir/build: MealDatabase
.PHONY : CMakeFiles/MealDatabase.dir/build

CMakeFiles/MealDatabase.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MealDatabase.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MealDatabase.dir/clean

CMakeFiles/MealDatabase.dir/depend:
	cd /home/christmas_fire/OOP_coursework/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christmas_fire/OOP_coursework /home/christmas_fire/OOP_coursework /home/christmas_fire/OOP_coursework/build /home/christmas_fire/OOP_coursework/build /home/christmas_fire/OOP_coursework/build/CMakeFiles/MealDatabase.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MealDatabase.dir/depend

