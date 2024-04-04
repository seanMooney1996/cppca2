//
// Created by Mooney on 4/1/2024.
//

#include "../headers/Board.h"
#include <iostream>

using namespace std;
Board::Board(const vector<Bug*> &bugs, int vecSize) {
    auto iter = bugs.begin();
    for (int i=0;i<vecSize;i++){
        Pair bugPos = (*iter)->getPosition();
        boardVector[bugPos.getX()][bugPos.getY()] = *iter;
        iter++;
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