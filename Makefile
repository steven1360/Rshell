# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/csmajs/struo014/rshell_remake/Rshell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csmajs/struo014/rshell_remake/Rshell

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake3 -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake3 -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake3 --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake3 -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/csmajs/struo014/rshell_remake/Rshell/CMakeFiles /home/csmajs/struo014/rshell_remake/Rshell/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/csmajs/struo014/rshell_remake/Rshell/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named rshell

# Build rule for target.
rshell: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 rshell
.PHONY : rshell

# fast build rule for target.
rshell/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/build
.PHONY : rshell/fast

#=============================================================================
# Target rules for targets named test

# Build rule for target.
test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test
.PHONY : test

# fast build rule for target.
test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/build
.PHONY : test/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) $(MAKESILENT) -f googletest/googlemock/CMakeFiles/gmock_main.dir/build.make googletest/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) $(MAKESILENT) -f googletest/googlemock/CMakeFiles/gmock.dir/build.make googletest/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) $(MAKESILENT) -f googletest/googletest/CMakeFiles/gtest_main.dir/build.make googletest/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) $(MAKESILENT) -f googletest/googletest/CMakeFiles/gtest.dir/build.make googletest/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

src/CommandToken.o: src/CommandToken.cpp.o

.PHONY : src/CommandToken.o

# target to build an object file
src/CommandToken.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/CommandToken.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/CommandToken.cpp.o
.PHONY : src/CommandToken.cpp.o

src/CommandToken.i: src/CommandToken.cpp.i

.PHONY : src/CommandToken.i

# target to preprocess a source file
src/CommandToken.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/CommandToken.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/CommandToken.cpp.i
.PHONY : src/CommandToken.cpp.i

src/CommandToken.s: src/CommandToken.cpp.s

.PHONY : src/CommandToken.s

# target to generate assembly for a file
src/CommandToken.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/CommandToken.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/CommandToken.cpp.s
.PHONY : src/CommandToken.cpp.s

src/ConnectorToken.o: src/ConnectorToken.cpp.o

.PHONY : src/ConnectorToken.o

# target to build an object file
src/ConnectorToken.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ConnectorToken.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/ConnectorToken.cpp.o
.PHONY : src/ConnectorToken.cpp.o

src/ConnectorToken.i: src/ConnectorToken.cpp.i

.PHONY : src/ConnectorToken.i

# target to preprocess a source file
src/ConnectorToken.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ConnectorToken.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/ConnectorToken.cpp.i
.PHONY : src/ConnectorToken.cpp.i

src/ConnectorToken.s: src/ConnectorToken.cpp.s

.PHONY : src/ConnectorToken.s

# target to generate assembly for a file
src/ConnectorToken.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ConnectorToken.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/ConnectorToken.cpp.s
.PHONY : src/ConnectorToken.cpp.s

src/Executor.o: src/Executor.cpp.o

.PHONY : src/Executor.o

# target to build an object file
src/Executor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Executor.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Executor.cpp.o
.PHONY : src/Executor.cpp.o

src/Executor.i: src/Executor.cpp.i

.PHONY : src/Executor.i

# target to preprocess a source file
src/Executor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Executor.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Executor.cpp.i
.PHONY : src/Executor.cpp.i

src/Executor.s: src/Executor.cpp.s

.PHONY : src/Executor.s

# target to generate assembly for a file
src/Executor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Executor.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Executor.cpp.s
.PHONY : src/Executor.cpp.s

src/IOToken.o: src/IOToken.cpp.o

.PHONY : src/IOToken.o

# target to build an object file
src/IOToken.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/IOToken.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/IOToken.cpp.o
.PHONY : src/IOToken.cpp.o

src/IOToken.i: src/IOToken.cpp.i

.PHONY : src/IOToken.i

# target to preprocess a source file
src/IOToken.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/IOToken.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/IOToken.cpp.i
.PHONY : src/IOToken.cpp.i

src/IOToken.s: src/IOToken.cpp.s

.PHONY : src/IOToken.s

# target to generate assembly for a file
src/IOToken.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/IOToken.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/IOToken.cpp.s
.PHONY : src/IOToken.cpp.s

src/Token.o: src/Token.cpp.o

.PHONY : src/Token.o

# target to build an object file
src/Token.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Token.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Token.cpp.o
.PHONY : src/Token.cpp.o

src/Token.i: src/Token.cpp.i

.PHONY : src/Token.i

# target to preprocess a source file
src/Token.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Token.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Token.cpp.i
.PHONY : src/Token.cpp.i

src/Token.s: src/Token.cpp.s

.PHONY : src/Token.s

# target to generate assembly for a file
src/Token.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Token.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Token.cpp.s
.PHONY : src/Token.cpp.s

src/Tokenizer.o: src/Tokenizer.cpp.o

.PHONY : src/Tokenizer.o

# target to build an object file
src/Tokenizer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Tokenizer.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Tokenizer.cpp.o
.PHONY : src/Tokenizer.cpp.o

src/Tokenizer.i: src/Tokenizer.cpp.i

.PHONY : src/Tokenizer.i

# target to preprocess a source file
src/Tokenizer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Tokenizer.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Tokenizer.cpp.i
.PHONY : src/Tokenizer.cpp.i

src/Tokenizer.s: src/Tokenizer.cpp.s

.PHONY : src/Tokenizer.s

# target to generate assembly for a file
src/Tokenizer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Tokenizer.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Tokenizer.cpp.s
.PHONY : src/Tokenizer.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

unit_tests/unit_test.o: unit_tests/unit_test.cpp.o

.PHONY : unit_tests/unit_test.o

# target to build an object file
unit_tests/unit_test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/unit_tests/unit_test.cpp.o
.PHONY : unit_tests/unit_test.cpp.o

unit_tests/unit_test.i: unit_tests/unit_test.cpp.i

.PHONY : unit_tests/unit_test.i

# target to preprocess a source file
unit_tests/unit_test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/unit_tests/unit_test.cpp.i
.PHONY : unit_tests/unit_test.cpp.i

unit_tests/unit_test.s: unit_tests/unit_test.cpp.s

.PHONY : unit_tests/unit_test.s

# target to generate assembly for a file
unit_tests/unit_test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/unit_tests/unit_test.cpp.s
.PHONY : unit_tests/unit_test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... gmock"
	@echo "... gmock_main"
	@echo "... gtest"
	@echo "... gtest_main"
	@echo "... rshell"
	@echo "... test"
	@echo "... src/CommandToken.o"
	@echo "... src/CommandToken.i"
	@echo "... src/CommandToken.s"
	@echo "... src/ConnectorToken.o"
	@echo "... src/ConnectorToken.i"
	@echo "... src/ConnectorToken.s"
	@echo "... src/Executor.o"
	@echo "... src/Executor.i"
	@echo "... src/Executor.s"
	@echo "... src/IOToken.o"
	@echo "... src/IOToken.i"
	@echo "... src/IOToken.s"
	@echo "... src/Token.o"
	@echo "... src/Token.i"
	@echo "... src/Token.s"
	@echo "... src/Tokenizer.o"
	@echo "... src/Tokenizer.i"
	@echo "... src/Tokenizer.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... unit_tests/unit_test.o"
	@echo "... unit_tests/unit_test.i"
	@echo "... unit_tests/unit_test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

