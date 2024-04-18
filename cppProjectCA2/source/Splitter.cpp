//
// Created by Mooney on 4/5/2024.
//

#include "../headers/Splitter.h"
#include <iostream>
#include <random>
#include <algorithm>

string Splitter::getBugDetails() {
    string bugDetails;
    bugDetails = to_string(id) + " SPLITTER (" + to_string(position.getX()) + "," + to_string(position.getY()) +
                 ") " + to_string(size) + " " + directionToString(
            direction) + " " + to_string(splitFrequency);

    if (alive) {
        bugDetails += " ALIVE ";
    } else {
        bugDetails += " DEAD ";
    }

    return bugDetails;
}

void Splitter::displayBug() {
    cout << getBugDetails() << endl;
}

// when splitter splits, its frequency for splitting is decreased( multiplied by 2)
void Splitter::split() {

    if (size % 2 != 0) {
        size -= 1;
    }
    this->size = size / 2;

    auto *newSplitter = new Splitter(id + size + this->getPosition().getX(), this->getPosition().getX(),
                                     this->getPosition().getY(),
                                     direction, size, splitFrequency * 2, board);
    this->travelDistance = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<Direction> directions = {Direction::North, Direction::South, Direction::East, Direction::West};
    std::shuffle(directions.begin(), directions.end(), gen);


    for (Direction dir: directions) {
        if (dir != this->direction && !newSplitter->isWayBlocked()) {
            newSplitter->direction = dir;
            break;
        }
    }

    cout << id << " has SPLIT!" << endl;
    // move the new splitter away from the original

    if (newSplitter->direction == Direction::North) {
        newSplitter->position.setX((newSplitter->position.getX()));
        cout << newSplitter->id << " id" << endl;
        cout << " y: " << newSplitter->getPosition().getY() << " x: " << newSplitter->getPosition().getX() << endl;
    } else if (newSplitter->direction == Direction::South) {
        newSplitter->position.setX((newSplitter->position.getX()));
        cout << " y: " << newSplitter->getPosition().getY() << " x: " << newSplitter->getPosition().getX() << endl;
    } else if (newSplitter->direction == Direction::East) {
        newSplitter->position.setY((newSplitter->position.getY()));
        cout << " y: " << newSplitter->getPosition().getY() << " x: " << newSplitter->getPosition().getX() << endl;
    } else if (newSplitter->direction == Direction::West) {
        newSplitter->position.setY((newSplitter->position.getY()));
        cout << " y: " << newSplitter->getPosition().getY() << " x: " << newSplitter->getPosition().getX() << endl;
    }
    board->addNewBugToBoard(newSplitter);
}

void Splitter::move() {


    while (this->isWayBlocked()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        int min = 1;
        int max = 4;
        std::uniform_int_distribution<> dist(min, max);
        int randomInt = dist(gen);

        if (randomInt == 1) {
            this->direction = Direction::North;
        } else if (randomInt == 2) {
            this->direction = Direction::South;
        } else if (randomInt == 3) {
            this->direction = Direction::East;
        } else if (randomInt == 4) {
            this->direction = Direction::West;
        }
    }

    if (this->direction == Direction::North) {
        this->position.setX((this->position.getX()) - 1);
    } else if (this->direction == Direction::South) {
        this->position.setX((this->position.getX()) + 1);
    } else if (this->direction == Direction::East) {
        this->position.setY((this->position.getY()) + 1);
    } else if (this->direction == Direction::West) {
        this->position.setY((this->position.getY()) - 1);
    }

    // if the travel distance is divisible by the split frequency, and size is greater than or equal to 4
    if (travelDistance==splitFrequency && size>=4) {
        split();
    }
    // increment the travel distance for splitter
    this->travelDistance += 1;
    this->path.push_back(this->position);
}


Splitter::Splitter(int id, int x, int y, Direction d, int size, int splitFreq, Board *board) {
    this->id = id;
    Pair p(x, y);
    this->position = p;
    this->direction = d;
    this->size = size;
    this->splitFrequency = splitFreq;
    this->alive = true;
    this->board = board;
}

string Splitter::getBugType() {
    return this->bugType;
}
