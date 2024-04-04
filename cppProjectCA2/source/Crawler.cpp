//
// Created by Mooney on 4/1/2024.
//

#include "../headers/Crawler.h"
#include <random>
#include <iostream>
using namespace std;
Crawler::Crawler(int id,int x,int y,Direction d,int size){
    this->id = id;
    Pair p(x,y);
    this->position = p;
    this->direction = d;
    this->size = size;
    this->alive = true;
}
void Crawler::move() {
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
            this->direction = Direction::South;
        } else if (randomInt == 3) {
            this->direction = Direction::East;
        } else if (randomInt == 4) {
            this->direction = Direction::West;
        }
    }

    if (this->direction ==  Direction::North) {
        this->position.setX((this->position.getX())-1);
    } else if (this->direction == Direction::South) {
        this->position.setX((this->position.getX())+1);
    } else if (this->direction == Direction::East) {
        this->position.setY((this->position.getY())+1);
    } else if (this->direction == Direction::West) {
        this->position.setY((this->position.getY())-1);
    }
    this->path.push_back(this->position);
}

void Crawler::displayBug() {
    cout << id << " CRAWLER (" << position.getX() << "," << position.getY() << ") " << size <<" "<< directionToString(
            direction);

    if (alive){
        cout<< "ALIVE" <<endl;
    } else {
        cout<< "DEAD" << endl;
    }
}
