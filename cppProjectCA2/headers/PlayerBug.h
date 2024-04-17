//
// Created by Mooney on 4/17/2024.
//

#ifndef CPPPROJECTCA2_PLAYERBUG_H
#define CPPPROJECTCA2_PLAYERBUG_H


#include "Crawler.h"

class PlayerBug : public Crawler{
private:
    string bugType = "Player";
public:
    PlayerBug(int id, int x, int y, Direction d, int size);
    void move() override;
    string getBugDetails() override;
    void setDirection(Direction d);
    string getBugType() override;
};



#endif //CPPPROJECTCA2_PLAYERBUG_H
