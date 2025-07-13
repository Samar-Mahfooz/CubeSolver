//
// Created by Samar on 05-07-2025.
//

#include <bits/stdc++.h>
#include "../Cube Modelling/RubiksCube.h"
#include "DFSSolver.h"

#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H


template <typename T, typename H>

class IDDFSSolver {
private:
    int max_search_depth;
    vector<RubiksCube::MOVES> total_moves;

public:
    T rubikscube;
    IDDFSSolver(T rubiksCube, int max_depth = 8) {
        this->max_search_depth = max_depth;
        this->rubikscube = rubiksCube;
    }

    vector<RubiksCube::MOVES> solve() {
        for (int i=1;i<=max_search_depth;i++) {
            DFSSolver<T, H> dfs_solver(rubikscube,i);
            total_moves = dfs_solver.solve();
            if (dfs_solver.rubikscube.isSolved()) {
                rubikscube = dfs_solver.rubikscube;
                break;
            }
        }

        return total_moves;
    }
};

#endif //IDDFSSOLVER_H
