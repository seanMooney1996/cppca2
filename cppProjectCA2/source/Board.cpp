//
// Created by Mooney on 4/1/2024.
//

#include "../headers/Board.h"


Board::Board(const list<Bug*> &bugs, int listSize) {
    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            this->boardVector[i][j] = nullptr;
        }
    }

    for (auto pointer: bugs){
        Pair bugPos = pointer->getPosition();
        boardVector[bugPos.getX()][bugPos.getY()] = pointer;
    }
}

void printBoard(){

}