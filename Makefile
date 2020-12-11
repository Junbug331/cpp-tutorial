CXX := g++
CXXFLAGS := -std=c++17

SRC := $(wildcard src/*.cpp)
TESTS := $(wildcard test/*.cpp)
INCL_DIR := include/

TARGET_NAME := CPPTutorial
TARGET_NAME_TESTS := CPPTutorial-test

$(TARGET_NAME):
	@mkdir build
	@$(CXX) $(CXXFLAGS) -I$(INCL_DIR) $(SRC) -o build/CPPTutorial

$(TARGET_NAME_TESTS):
	@mkdir build/test
	@$(CXX) $(CXXFLAGS) $(TESTS) -o build/test/CPPTutorial-test

clean:
	@rm -r -f build && rm -r -f build/test