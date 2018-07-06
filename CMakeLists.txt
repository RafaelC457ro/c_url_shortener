# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(c_url_shorter)
# Set the output folder where your program will be created
# get from env variables
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# The following folder will be included
include_directories(PROJECT_SOURCE_DIR)

add_executable(shorter ${PROJECT_SOURCE_DIR}/shortener.c)
