cmake_minimum_required(VERSION 3.21)
project(ClientApp)

set(CMAKE_CXX_STANDARD 20)
set(FIND_NUMBER_PATHS ../Number)
set(FIND_VECTOR_PATHS ../Vector)

find_path(NUMBER_INCLUDE_DIR Number.h
        PATHS ${FIND_NUMBER_PATHS})

find_path(VECTOR_INCLUDE_DIR Vector.h
        PATHS ${FIND_VECTOR_PATHS})

include_directories(${NUMBER_INCLUDE_DIR} ${VECTOR_INCLUDE_DIR})

find_library(NUMBER_LIBRARY
        NAMES Number
        PATH_SUFFIXES build
        PATHS ${FIND_NUMBER_PATHS})

find_library(VECTOR_LIBRARY
        NAMES Vector
        PATH_SUFFIXES build
        PATHS ${FIND_VECTOR_PATHS})

add_executable(ClientApp ClientApp.cpp ${NUMBER_LIBRARY} ${VECTOR_LIBRARY})

target_link_libraries(${PROJECT_NAME} ${NUMBER_LIBRARY} ${VECTOR_LIBRARY})
