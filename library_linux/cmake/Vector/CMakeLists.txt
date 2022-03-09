cmake_minimum_required(VERSION 3.21)
project(Vector)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(FIND_NUMBER_PATHS ../Number)

find_path(NUMBER_INCLUDE_DIR Number.h
        PATHS ${FIND_NUMBER_PATHS})

include_directories(${NUMBER_INCLUDE_DIR})

add_library(Vector SHARED Vector.cpp Vector.h)
