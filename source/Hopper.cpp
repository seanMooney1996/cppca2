//
// Created by Mooney on 4/1/2024.
//

#include "../headers/Hopper.h"
#include <random>
#include <iostream>

using namespace std;


Hopper::Hopper(int id,int x,int y,Direction d,int size, int hop_length){
    this->id = id;
    Pair p(x,y);
    this->position = p;
    this->direction = d;
    this->size = size;
    this->hopLength=hop_length;
    this->alive = true;
}
void Hopper::move() {
    while (this->isWayBlocked()) {
         std::random_device rd;
         std::mt19937 gen(rd());
        int min = 1;
        int max = 4;
        std::uniform_int_distribution<> dist(min, max);
        int randomInt = dist(gen);

        if (randomInt == 1) {
            this->direction =  Direction::North;
        } else if (randomInt == 2) {
            this->direction =  Direction::South;
        } else if (randomInt == 3) {
            this->direction =  Direction::East;
        } else if (randomInt == 4) {
            this->direction =  Direction::West;
        }
    }

    if (this->direction ==  Direction::North) {
        this->position.setX(this->position.getX()-this->hopLength);
        if (this->getPosition().getX()<0){
            this->position.setX(0);
        }
    } else if (this->direction ==  Direction::South) {
        this->position.setX(this->position.getX()+this->hopLength);
        if (this->getPosition().getX()>9){
            this->position.setX(9);
        }
    } else if (this->direction ==  Direction::East) {
        this->position.setY(this->position.getY()+this->hopLength);
        if (this->getPosition().getY()>9){
            this->position.setY(9);
        }
    } else if (this->direction ==  Direction::West) {
        this->position.setY(this->position.getY()-this->hopLength);
        if (this->getPosition().getY()<0){
            this->position.setY(0);
        }
    }

    this->path.push_back(position);
}

void Hopper::displayBug() {
    cout<<getBugDetails()<<endl;
}

string Hopper::getBugDetails() {
    string bugDetails;
    bugDetails = to_string(id) + " HOPPER (" + to_string(position.getX()) + "," + to_string(position.getY()) +
                 ") " + to_string(size) +" "+ directionToString(
            direction) + " " + to_string(hopLength);
    if (alive){
        bugDetails += " ALIVE ";
    } else {
        bugDetails += " DEAD ";
    }

    return bugDetails;
}

string Hopper::getBugType() {
    return this->bugType;
}
