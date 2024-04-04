//
// Created by Mooney on 4/1/2024.
//

#include "../headers/Board.h"
#include <iostream>

using namespace std;
Board::Board(const vector<Bug*> &bugs) {
    bugsVector=bugs;
    getBugPositions();
}

void Board::tapBugBoard() {
    moveAllBugs();
    getBugPositions();
}

void Board::getBugPositions() {
    auto iter = bugsVector.begin();
    for (int i=0;i<bugsVector.size();i++){
        Pair bugPos = (*iter)->getPosition();
        boardVector[bugPos.getX()][bugPos.getY()] = *iter;
        iter++;
    }
    printBoard();
}
void Board::moveAllBugs() {
    for (int i=0;i<bugsVector.size();i++){
        bugsVector[i]->move();
    }
}
void Board::printBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "| ";
            if (this->boardVector[i][j] != nullptr) {
                Bug *b = this->boardVector[i][j];
                cout << b->getSize();
            } else {
                cout << "X";
            }
            cout<< " |";
            if (j==9){
                cout<<endl;
            }
        }
    }
}


