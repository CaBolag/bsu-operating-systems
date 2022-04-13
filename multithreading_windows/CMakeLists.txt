cmake_minimum_required(VERSION 3.17)
project(multithreading_windows)

set(CMAKE_CXX_STANDARD 20)

add_executable(multithreading_windows main.cpp Matrix.cpp Matrix.h MatrixMultiplicator.cpp MatrixMultiplicator.h)