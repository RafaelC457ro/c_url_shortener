# Specif tnlProject_Adde minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name
project(c_url_shorter)

#include ExternalProject module
include(ExternalProject)


ExternalProject_Add(
    criterion
    GIT_REPOSITORY https://github.com/Snaipe/Criterion
    GIT_TAG master
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
    PREFIX criterion
)

ExternalProject_Get_Property(criterion source_dir binary_dir)


# get from env variables
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)


# The following folder will be included
include_directories(PROJECT_SOURCE_DIR)

add_executable(shorter ${PROJECT_SOURCE_DIR}/shortener.c)
