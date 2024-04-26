//
// Created by Mooney on 4/17/2024.
//

#include "../headers/PlayerBug.h"
using namespace std;
void PlayerBug::move() {
    if (this->direction ==  Direction::North) {
        this->position.setX((this->position.getX())-1);
    } else if (this->direction == Direction::South) {
        this->position.setX((this->position.getX())+1);
    } else if (this->direction == Direction::East) {
        this->position.setY((this->position.getY())+1);
    } else if (this->direction == Direction::West) {
        this->position.setY((this->position.getY())-1);
    }
}

string PlayerBug::getBugDetails() {
    return Crawler::getBugDetails() + " PLAYER BUG!!!";
}




void PlayerBug::setDirection(Direction d) {
this->direction= d;
}

string PlayerBug::getBugType() {
    return this->bugType;
}

PlayerBug::PlayerBug(int id, int x, int y, Direction d, int size) : Crawler(id, x, y, d, size) {
    this->id = id;
    Pair p(x,y);
    this->position = p;
    this->direction = d;
    this->size = size;
    this->alive = true;
}
