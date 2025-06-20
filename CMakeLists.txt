cmake_minimum_required(VERSION 3.31)
project(CubeSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(CubeSolver main.cpp
        cmake-build-debug/RubiksCube.cpp
        cmake-build-debug/RubiksCube.h
        cmake-build-debug/RubiksCube3Darray.cpp
        cmake-build-debug/RubiksCube1Darray.cpp
)
