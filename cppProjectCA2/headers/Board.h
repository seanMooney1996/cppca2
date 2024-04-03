//
// Created by Mooney on 4/1/2024.
//

#ifndef CPPPROJECTCA2_BOARD_H
#define CPPPROJECTCA2_BOARD_H
#include <vector>
#include <list>
#include "Bug.h"

class Board {
private:
    vector<vector<Bug*>> boardVector;

public:
    Board(const list<Bug*> &bugs,int listSize);
    void printBoard();
};


#endif //CPPPROJECTCA2_BOARD_H
