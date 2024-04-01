//
// Created by Mooney on 4/1/2024.
//

#include "../headers/Crawler.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());


void Crawler::move() {
    while (this->isWayBlocked()) {
        int min = 1;
        int max = 4;
        std::uniform_int_distribution<> dist(min, max);
        int randomInt = dist(gen);

        if (randomInt == 1) {
            this->direction = NORTH;
        } else if (randomInt == 2) {
            this->direction = SOUTH;
        } else if (randomInt == 3) {
            this->direction = EAST;
        } else if (randomInt == 4) {
            this->direction = WEST;
        }
    }

    if (this->direction == NORTH) {
        this->position.setY(this->position.getY()-1);
    } else if (this->direction == SOUTH) {
        this->position.setY(this->position.getY()+1);
    } else if (this->direction == EAST) {
        this->position.setX(this->position.getX()+1);
    } else if (this->direction == WEST) {
        this->position.setX(this->position.getX()-1);
    }
}
