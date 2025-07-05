//
// Created by Samar on 03-07-2025.
//
#include <bits/stdc++.h>
#include "../Cube Modelling/RubiksCube.h"

#ifndef BFSSOLVER_H
#define BFSSOLVER_H

template<typename  T, typename H> // T rubikscube rep and H corresponding hash function //
class BFSSolver {
private:
    vector<RubiksCube::MOVES> total_moves;
    unordered_map<T, bool, H> visited;
    unordered_map<T, RubiksCube::MOVES, H> move_done;

    T bfs() {
        queue<T> q;
        q.push(rubikscube);
        visited[rubikscube] = true;

        while (!q.empty()) {
            T node = q.fron();
            q.pop();

            if (node.isSolved()) {
                return node;
            }

            for (int i=0;i<18;i++) {
                auto curr_move = RubiksCube::MOVES(i);
                node.move(curr_move);
                if (!visited[node]) {
                    visited[node] = true;
                    q.push(node);
                    move_done[curr_move] = true;
                }
                move.invert(curr_move);
            }
        }

        return rubikscube;
    }

public:
    T rubikscube;
    BFSSolver(T rubikscube) {
        this->rubikscube = rubikscube;
    }

    vector<RubiksCube::MOVES> solve() {
        T solved_cube = bfs();
        assert(solved_cube.isSolved());

        T current_cube = solved_cube;
        vector<RubiksCube::MOVES> total_moves;
        while (!(current_cube == rubikscube)) {
            RubiksCube::MOVES curr_move = move_done[current_cube];
            total_moves.push_back(curr_move);
            current_cube.invert(curr_move);
        }

        rubikscube = solved_cube;
        reverse(total_moves.begin(), total_moves.end());
        return total_moves;
    }
};

#endif //BFSSOLVER_H
