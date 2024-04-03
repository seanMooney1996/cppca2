//
// Created by Mooney on 4/1/2024.
//

#ifndef CPPPROJECTCA2_HOPPER_H
#define CPPPROJECTCA2_HOPPER_H


#include "Bug.h"

class Hopper : public Bug {
public:
    Hopper(int id,int x,int y,Direction d,int size, int hop_length);
    void move() override;
    void displayBug() override;

private:
    int hopLength;
};


#endif //CPPPROJECTCA2_HOPPER_H
