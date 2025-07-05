//
// Created by Samar on 03-07-2025.
//

#include <bits/stdc++.h>
#include "../Cube Modelling/RubiksCube.h"

#ifndef DFSSOLVER_H
#define DFSSOLVER_H

template<typename  T, typename H>

class DFSSolver {
private:
    vector<RubiksCube::MOVES> total_moves;
    int max_search_depth;

    bool dfs(int dep) {
        if (rubikscube.isSolved()) return true;
        if (dep>max_search_depth) return false;

        for (int i=0;i<18;i++) {
            rubikscube.move(RubiksCube::MOVES(i));
            total_moves.push_back(RubiksCube::MOVES(i));
            if (dfs(dep+1)) return true;
            total_moves.pop_back();
            rubikscube.invert(RubiksCube::MOVES(i));
        }

        return false;
    }

public:
    T rubikscube;
    DFSSolver(T rubiksCube, int max_dep = 8) {
        this->rubikscube = rubikscube;
        this->max_search_depth = max_dep;
    }

    vector<RubiksCube::MOVES> solve() {
        dfs(1);
        return total_moves;
    }
};


#endif //DFSSOLVER_H
