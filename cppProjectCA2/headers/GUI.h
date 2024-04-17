//
// Created by seanm on 17/04/2024.
//

#ifndef CPPPROJECTCA2_GUI_H
#define CPPPROJECTCA2_GUI_H
#include <vector>
#include "Bug.h"
#include "Board.h"
#include <SFML/Graphics.hpp>

class GUI {

private:
    Board& board;

public:
    GUI(Board &board);
    void begin();
    static void draw(sf::RenderWindow &window,const Bug& bug);
};


#endif //CPPPROJECTCA2_GUI_H
