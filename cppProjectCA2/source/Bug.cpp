#include "../headers/Bug.h"
#include "../headers/Direction.h"

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

void Bug::setPosition(const Pair &pos) {
    Bug::position = pos;
}

bool Bug::isWayBlocked() {
    if (this->direction ==  Direction::North){
        if (this->getPosition().getY()-1 == -1){
            return true;
        }
    }
    if (this->direction ==  Direction::South){
        if (this->getPosition().getY()+1 == 10){
            return true;
        }
    }
    if (this->direction ==  Direction::East){
        if (this->getPosition().getX()+1 == 10){
            return true;
        }
    }
    if (this->direction ==  Direction::West){
        if (this->getPosition().getX()-1 == -1){
            return true;
        }
    }
    return false;
};
