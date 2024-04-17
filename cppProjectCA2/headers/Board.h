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
    Board();
    void initializeBoard(vector<Bug*> &bugsVec);
    void printBoard();
    void moveAllBugs();
    void tapBugBoard();
    void getBugPositions();
    void displayLifeHistory();
    void writeHistoryToFile();
    static string getBugLifeHistory(Bug* bug);
    void displayAllCells();
    void runSimulation();
    void displayAllBugs();
    void addNewBugToBoard(Bug *bug);
    vector<Bug*>& getBugsVec();
};


#endif //CPPPROJECTCA2_BOARD_H
