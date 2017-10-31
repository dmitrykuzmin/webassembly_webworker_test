cmake_minimum_required(VERSION 2.8)
project(test)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_definitions("-std=gnu++11")

add_definitions("-O2")

add_definitions(-s USE_SDL=2)

set(OUT_DIR ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR})

include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})

set (CORELIB_FILES string_container.cpp string_container.h main.cpp)

add_library(test STATIC ${CORELIB_FILES})
