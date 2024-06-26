//
// Created by Mooney on 4/1/2024.
//

#ifndef CPPPROJECTCA2_BUG_H
#define CPPPROJECTCA2_BUG_H
#include <list>
#include "Direction.h"

struct Pair {
    int getX() const;

    int getY() const;

    void setX(int xNew){
        x = xNew;
    }

    void setY(int yNew){
        y=yNew;
    }

    int x;
    int y;

    Pair(int newx,int newy){
        x = newx;
        y = newy;
    }

    bool operator==( const Pair& other) const {
        if(other.x==x && other.y== y)
            return true;
        else
            return false;
    }

    bool operator<(const Pair& other) const {
        if (x < other.x)
            return true;
        else if (x == other.x)
            return y < other.y;
        else
            return false;

    }
};

using namespace std;

class Bug {


protected:
    int id;
    Pair position = Pair(0,0);
    Direction direction;
    int size;
    bool alive;
    list<Pair> path;
    int eatenBy = -1;

public:
    virtual void displayBug() =0;
    virtual void move() =0;
    virtual string getBugDetails() =0;
    virtual string getBugType() = 0;

    virtual ~Bug() = default;

    
    void eatBug(Bug *bug);
    bool isWayBlocked();

    void setSize(int size);

    int getId() const;

    void setAlive(bool alive);

    const Pair &getPosition() const;

    Direction getDirection() const;

    int getSize() const;

    bool isAlive() const;

    const list<Pair> &getPath() const;

    void setPosition(const Pair &position);

    void setEatenBy(int eatenBy);

    int getEatenBy() const;
};

#endif //CPPPROJECTCA2_BUG_H
