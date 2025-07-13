
#include <bits/stdc++.h>
#include "Solvers/DFSSolver.h"
#include "Solvers/BFSSolver.h"
#include "Solvers/IDDFSSolver.h"
#include "Solvers/IDAstarSolver.h"
//#include "PatternDatabases/CornerPatternDatabase.h"
#include "Pattern Databases/CornerDBMaker.h"

using namespace std;

int main() {
    string fileName = "C:\\Users\\Samar\\Downloads\\cornerDepth5V1 (1).txt";
    RubiksCubeBitboard cube;
    auto shuffleMoves = cube.randomshuffleCube(8);
    cube.print();
    for (auto move: shuffleMoves) cout << cube.getMOVE(move) << " ";
    cout << "\n";

    IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    auto moves = idaStarSolver.solve();

    idaStarSolver.rubiksCube.print();
    for (auto move: moves) cout << cube.getMOVE(move) << " ";
    cout << "\n";

    return 0;
}
