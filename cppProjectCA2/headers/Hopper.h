//
// Created by Mooney on 4/1/2024.
//

#ifndef CPPPROJECTCA2_HOPPER_H
#define CPPPROJECTCA2_HOPPER_H


#include "Bug.h"

class Hopper : public Bug {
public:
    Hopper(int id,int x,int y,Direction d,int size, int hop_length);
    string getBugDetails() override;
    void move() override;
    void displayBug() override;
     string getBugType() override;
private:
    int hopLength;
    string bugType = "Hopper";
};


#endif //CPPPROJECTCA2_HOPPER_H
