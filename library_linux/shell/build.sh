#!/bin/bash

build_number_library(){
    echo "BUILDING NUMBER LIBRARY..."
    g++ -c Number/Number.cpp -o build/Number.o
    ar rvs build/Number.a build/Number.o
    echo "BUILDING NUMBER LIBRARY DONE"
}

build_vector_library(){
    echo "BUILDING VECTOR LIBRARY..."
    g++ -c -INumber Vector/Vector.cpp -o build/Vector.o
    g++ -shared -o build/libVector.so build/Vector.o build/Number.a
    echo "BUILDING VECTOR LIBRARY DONE"
}

build_client_app(){
    echo "BUILDING CLIENT APP..."
    g++ -o build/ClientApp  ClientApp/ClientApp.cpp -INumber -IVector build/Number.a  build/libVector.so 
    #g++ -INumber -IVector -Lbuild/ -lVector ClientApp/ClientApp.cpp -o build/ClientApp
    echo "BUILDING CLIENT APP DONE"
}

build(){
    [-d build] || mkdir build
    build_number_library && build_vector_library && build_client_app
}

run(){
    echo "RINNING CLIENT APP..."
    ./build/ClientApp
}

clean(){
    echo "DELETING BUILD FILES..."
    rm -rf build
    echo "BUILD FILES DELETED"
}

build
run
clean