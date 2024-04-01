//
// Created by Mooney on 4/1/2024.
//

#include "../headers/Hopper.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

void Hopper::move() {
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
        this->position.setY(this->position.getY()-this->hopLength);
        if (this->getPosition().getY()<0){
            this->position.setY(0);
        }
    } else if (this->direction == SOUTH) {
        this->position.setY(this->position.getY()+this->hopLength);
        if (this->getPosition().getY()>9){
            this->position.setY(9);
        }
    } else if (this->direction == EAST) {
        this->position.setX(this->position.getX()+this->hopLength);
        if (this->getPosition().getX()>9){
            this->position.setX(9);
        }
    } else if (this->direction == WEST) {
        this->position.setY(this->position.getX()-this->hopLength);
        if (this->getPosition().getX()<0){
            this->position.setX(0);
        }
    }

    this->path.push_back(position);
}
