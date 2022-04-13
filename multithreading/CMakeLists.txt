cmake_minimum_required(VERSION 3.17)
project(Multithreading)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS
        Matrix.h
        MatrixMultiplicator.h
        )
set(PROJECT_SOURCES
        main.cpp
        Matrix.cpp
        MatrixMultiplicator.cpp
        )

add_executable(Multithreading ${PROJECT_SOURCES} ${PROJECT_HEADERS})