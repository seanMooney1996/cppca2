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
    vector<vector<Bug*>> boardVector = {
            {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
            {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
            {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
            {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
            {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
            {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
            {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
            {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
            {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr},
            {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr}
    };

    vector<Bug*> bugsVector;

public:
    Board(const vector<Bug*> &bugs);
    void printBoard();
    void moveAllBugs();
    void tapBugBoard();
    void getBugPositions();
};


#endif //CPPPROJECTCA2_BOARD_H
