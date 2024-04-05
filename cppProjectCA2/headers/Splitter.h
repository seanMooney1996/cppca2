//
// Created by Mooney on 4/5/2024.
//

#ifndef CPPPROJECTCA2_SPLITTER_H
#define CPPPROJECTCA2_SPLITTER_H


#include <vector>
#include "Bug.h"
#include "Board.h"

class Splitter: public Bug {
protected:
    int splitFrequency;
    int travelDistance = 0;
    Board *board;
public:
    string getBugDetails() override;
    void displayBug() override;
    void move() override;
    void split();
    Splitter(int id, int x, int y, Direction d, int size, int splitFreq,Board *board);
};


#endif //CPPPROJECTCA2_SPLITTER_H
