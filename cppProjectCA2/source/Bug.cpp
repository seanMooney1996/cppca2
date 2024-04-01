#include "../headers/Bug.h"


int Pair::getX() const {
    return x;
}

int Pair::getY() const {
    return y;
}


int Bug::getId() const {
    return id;
}

const Pair &Bug::getPosition() const {
    return position;
}

Direction Bug::getDirection() const {
    return direction;
}

int Bug::getSize() const {
    return size;
}

bool Bug::isAlive() const {
    return alive;
}

const list<Pair> &Bug::getPath() const {
    return path;
}

bool Bug::isWayBlocked() {
    if (this->direction == NORTH){
        if (this->getPosition().getY()-1 == -1){
            return true;
        }
    }
    if (this->direction == SOUTH){
        if (this->getPosition().getY()+1 == 10){
            return true;
        }
    }
    if (this->direction == EAST){
        if (this->getPosition().getX()+1 == 10){
            return true;
        }
    }
    if (this->direction == WEST){
        if (this->getPosition().getX()-1 == -1){
            return true;
        }
    }
    return false;
};
