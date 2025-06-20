//
// Created by Samar on 15-06-2025.
//

#include "RubiksCube.h"

char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::BLUE:
            return 'B';

        case COLOR::GREEN:
            return 'G';

        case COLOR::RED:
            return 'R';

        case COLOR::WHITE:
            return 'W';

        case COLOR::YELLOW:
            return 'Y';

        case COLOR::ORANGE:
            return 'O';
    }
}

string RubiksCube::getMOVE(MOVES ind) {
    switch (ind) {
        case MOVES::L:
            return "L";
        case MOVES::LPRIME:
            return "L'";
        case MOVES::L2:
            return "L2";
        case MOVES::R:
            return "R";
        case MOVES::RPRIME:
            return "R'";
        case MOVES::R2:
            return "R2";
        case MOVES::U:
            return "U";
        case MOVES::UPRIME:
            return "U'";
        case MOVES::U2:
            return "U2";
        case MOVES::D:
            return "D";
        case MOVES::DPRIME:
            return "D'";
        case MOVES::D2:
            return "D2";
        case MOVES::F:
            return "F";
        case MOVES::FPRIME:
            return "F'";
        case MOVES::F2:
            return "F2";
        case MOVES::B:
            return "B";
        case MOVES::BPRIME:
            return "B'";
        case MOVES::B2:
            return "B2";
    }
}


RubiksCube &RubiksCube::moves(MOVES ind) {
    switch (ind) {
        case MOVES::L:
            return this->l();
        case MOVES::LPRIME:
            return this->lPrime();
        case MOVES::L2:
            return this->l2();
        case MOVES::R:
            return this->r();
        case MOVES::RPRIME:
            return this->rPrime();
        case MOVES::R2:
            return this->r2();
        case MOVES::U:
            return this->u();
        case MOVES::UPRIME:
            return this->uPrime();
        case MOVES::U2:
            return this->u2();
        case MOVES::D:
            return this->d();
        case MOVES::DPRIME:
            return this->dPrime();
        case MOVES::D2:
            return this->d2();
        case MOVES::F:
            return this->f();
        case MOVES::FPRIME:
            return this->fPrime();
        case MOVES::F2:
            return this->f2();
        case MOVES::B:
            return this->b();
        case MOVES::BPRIME:
            return this->bPrime();
        case MOVES::B2:
            return this->b2();
    }
}

RubiksCube &RubiksCube::invert(MOVES ind) {
    switch (ind) {
        case MOVES::L:
            return this->lPrime();
        case MOVES::LPRIME:
            return this->l();
        case MOVES::L2:
            return this->l2();
        case MOVES::R:
            return this->rPrime();
        case MOVES::RPRIME:
            return this->r();
        case MOVES::R2:
            return this->r2();
        case MOVES::U:
            return this->uPrime();
        case MOVES::UPRIME:
            return this->u();
        case MOVES::U2:
            return this->u2();
        case MOVES::D:
            return this->dPrime();
        case MOVES::DPRIME:
            return this->d();
        case MOVES::D2:
            return this->d2();
        case MOVES::F:
            return this->fPrime();
        case MOVES::FPRIME:
            return this->f();
        case MOVES::F2:
            return this->f2();
        case MOVES::B:
            return this->bPrime();
        case MOVES::BPRIME:
            return this->b();
        case MOVES::B2:
            return this->b2();
    }
}

void RubiksCube::print() const {
    cout << "Rubiks Cube: \n\n";
    /*
     * Structure :
     *    U
     *  L F R B
     *    D
     */
    // print the top face //
    for (int row = 0;row<=2;row++) {
        for (int i=0;i<7;i++) cout<<" ";
        for (int col = 0;col<3;col++) {
            cout<<getColorLetter(getcolor(FACE::UP, row, col))<<" ";
        }
        cout<<"\n";
    }

    for (int row = 0;row<3;row++) {
        // print the left face //
        for (int col= 0;col<3;col++) {
            cout<<getColorLetter(getcolor(FACE::LEFT, row, col))<<" ";
        }
        // print the front face //
        for (int col = 0;col<3;col++) {
            cout<<getColorLetter(getcolor(FACE::FRONT, row, col))<<" ";
        }
        // print the right face //
        for (int col = 0;col<3;col++) {
            cout<<getColorLetter(getcolor(FACE::RIGHT, row, col))<<" ";
        }
        // print the back face //
        for (int col = 0;col<3;col++) {
            cout<<getColorLetter(getcolor(FACE::BACK, row, col))<<" ";
        }
        cout<<"\n";
    }

    // print the down face //
    for (int row = 0;row<3;row++) {
        for (int i=0;i<7;i++) cout<<" ";
        for (int col = 0;col<3;col++) {
            cout<<getColorLetter(getcolor(FACE::DOWN, row, col))<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

vector<RubiksCube::MOVES> RubiksCube::randomshuffleCube(unsigned int times) {
    vector<MOVES> moves_performed;
    srand(time(0));

    for (int i=0;i<times;i++) {
        int selectMove = (rand() % 18);
        moves_performed.push_back(static_cast<MOVES>(selectMove));
        this->moves(static_cast<MOVES>(selectMove));
    }
    return moves_performed;
}

string RubiksCube::getCornerColorString(int ind) const {
    string str = "";
    switch (ind) {
        // UFR//
        case 0:
            str += getColorLetter(getcolor(FACE::UP, 2,2));
            str += getColorLetter(getcolor(FACE::FRONT, 0,2));
            str += getColorLetter(getcolor(FACE::RIGHT, 0,0));
            break;

        // UFL //
        case 1:
            str += getColorLetter(getcolor(FACE::UP, 2, 0));
            str += getColorLetter(getcolor(FACE::FRONT, 0, 0));
            str += getColorLetter(getcolor(FACE::LEFT, 0, 2));
            break;
        // UBL //
        case 3:
            str += getColorLetter(getcolor(FACE::UP, 0, 2));
            str += getColorLetter(getcolor(FACE::BACK, 0, 0));
            str += getColorLetter(getcolor(FACE::RIGHT, 0, 2));
            break;

        // DFR //
        case 4:
            str += getColorLetter(getcolor(FACE::DOWN, 0, 2));
            str += getColorLetter(getcolor(FACE::FRONT, 2, 2));
            str += getColorLetter(getcolor(FACE::RIGHT, 2, 0));
            break;

        // DFL //
        case 5:
            str += getColorLetter(getcolor(FACE::DOWN, 0, 0));
            str += getColorLetter(getcolor(FACE::FRONT, 2, 0));
            str += getColorLetter(getcolor(FACE::LEFT, 2, 2));
            break;

        // DBR //
        case 6:
            str += getColorLetter(getcolor(FACE::DOWN, 2, 2));
            str += getColorLetter(getcolor(FACE::BACK, 2, 0));
            str += getColorLetter(getcolor(FACE::RIGHT, 2, 2));
            break;

        // DBL //
        case 7:
            str += getColorLetter(getcolor(FACE::DOWN, 2, 0));
            str += getColorLetter(getcolor(FACE::BACK, 2, 2));
            str += getColorLetter(getcolor(FACE::LEFT, 2, 0));
            break;
    }
    return str;
}


int RubiksCube::getCornerIndex(int ind) const {
    string corner = getCornerColorString(ind);

    int ret = 0;
    for (auto c:corner) {
        if (c!='B' && c!='G') continue;
        if (c == 'G') ret |= (1<<0);
    }

    for (auto c:corner) {
        if (c!='R' && c!='O') continue;
        if (c == 'O') ret |= (1<<1);
    }

    for (auto c:corner) {
        if (c!='W' && c!='Y') continue;
        if (c == 'Y') ret |= (1<<2);
    }

    return ret;
}

int RubiksCube::getCornerOrientation(int ind) const {
    string corner = getCornerColorString(ind);

    string actual_str = "";
    for (auto c:corner) {
        if (c!='W' && c!='Y') continue;
        actual_str += c;
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    }
    else if (corner[2] == actual_str[0]) {
        return 2;
    }
    else return 0;
}







