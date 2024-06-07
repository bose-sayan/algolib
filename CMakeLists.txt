cmake_minimum_required(VERSION 3.10)
project(algolib)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Include the headers
include_directories(include)

# Add the main executable
add_executable(main src/main.cpp)

# Add a test executable
file(GLOB TEST_SOURCES tests/*.cpp)
add_executable(tests ${TEST_SOURCES})