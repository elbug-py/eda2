
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# set the project name

project(parenthesis
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_subdirectory(src)
#add_subdirectory(tests)

add_executable(test test/check_tags.cpp src/node.cpp src/stack.cpp)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/include)


# add the executable