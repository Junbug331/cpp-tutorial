cmake_minimum_required(VERSION 3.16.3)
project(CPPTutorial)

option(BUILD_TESTS "Turn on build for tests of CPPTutorial" OFF)
set(CMAKE_CXX_STANDARD 17)
set(OUTPUT_ELF ${CMAKE_PROJECT_NAME})
set(SRC_FILES 
    src/Board.cpp
    src/Game.cpp
    src/main.cpp
)
set(INC_FILES_DIR
    include/
)

if (BUILD_TESTS)
    add_subdirectory(test)
endif()

include_directories(
    ${INC_FILES_DIR}
)

add_executable(${OUTPUT_ELF} ${SRC_FILES})
