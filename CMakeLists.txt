# Require CMAKE 3.1 or higher
cmake_minimum_required(VERSION 3.1)

# Project name
project(snake)

# Build for C++20 if we can
set(CMAKE_CXX_STANDARD 20)

# set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fsanitize=address")

# Any source files in this directory
set(SOURCE_FILES snake/main.cpp config.h)

set(LIBRARY_NAME snake-engine)

# Where any include files are
include_directories(engine)

# Subdirectories to build
add_subdirectory(engine)
add_subdirectory(tests)

# Name of executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link
target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME})
target_link_libraries(${PROJECT_NAME} sfml-graphics)
target_link_libraries(${PROJECT_NAME} sfml-window)
target_link_libraries(${PROJECT_NAME} sfml-system)

# copy assets folder
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
