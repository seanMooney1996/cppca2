//
// Created by Mooney on 4/1/2024.
//

#ifndef CPPPROJECTCA2_CRAWLER_H
#define CPPPROJECTCA2_CRAWLER_H


#include "Bug.h"

class Crawler : public Bug {
public:
    string getBugDetails() override;
    void displayBug() override;
    void move() override;
    Crawler(int id, int x, int y, Direction d, int size);

};


#endif //CPPPROJECTCA2_CRAWLER_H
