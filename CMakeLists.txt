# Specif tnlProject_Adde minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name
project(c_url_shortener)

enable_testing()

# get from env variables
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# The following folder will be included
include_directories(PROJECT_SOURCE_DIR)
add_subdirectory(test)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/*.c)
file(GLOB HEADERS  ${PROJECT_SOURCE_DIR}/*.h) 

add_library(short ${SOURCES} ${HEADERS})
add_executable(shortener  ${PROJECT_SOURCE_DIR}/shortener.c)
