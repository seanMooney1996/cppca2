//
// Created by Mooney on 4/3/2024.
//

#ifndef CPPPROJECTCA2_DIRECTION_H
#define CPPPROJECTCA2_DIRECTION_H


#include <string>

enum class Direction {
    North,
    South,
    East,
    West
};

inline std::string directionToString(Direction dir) {
    switch (dir) {
        case Direction::North:
            return "North";
        case Direction::South:
            return "South";
        case Direction::East:
            return "East";
        case Direction::West:
            return "West";
        default:
            return "None";
    }
}

#endif //CPPPROJECTCA2_DIRECTION_H
