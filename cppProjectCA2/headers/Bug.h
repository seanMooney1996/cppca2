//
// Created by Mooney on 4/1/2024.
//

#ifndef CPPPROJECTCA2_BUG_H
#define CPPPROJECTCA2_BUG_H
#include <list>

struct Pair {
    int getX() const;

    int getY() const;

    void setX(int x);

    void setY(int y);

    int x;
    int y;
};

enum class Direction {
    North,
    South,
    East,
    West
};

using namespace std;

class Bug {


protected:
    int id;
    Pair position;
    Direction direction;
    int size;
    bool alive;
    list<Pair> path;

public:
    virtual void move() =0;
    bool isWayBlocked();

    int getId() const;

    const Pair &getPosition() const;

    Direction getDirection() const;

    int getSize() const;

    bool isAlive() const;

    const list<Pair> &getPath() const;

    void setPosition(const Pair &position);
};


#endif //CPPPROJECTCA2_BUG_H
