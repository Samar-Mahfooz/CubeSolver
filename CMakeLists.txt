cmake_minimum_required(VERSION 3.31)
project(CubeSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(CubeSolver main.cpp
        "Cube Modelling/RubiksCube.cpp"
        "Cube Modelling/RubiksCube.h"
        "Cube Modelling/RubiksCube3Darray.cpp"
        "Cube Modelling/RubiksCube1Darray.cpp"
        Solvers/BFSSolver.h
        Solvers/DFSSolver.h
)
