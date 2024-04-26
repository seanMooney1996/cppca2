//
// Created by seanm on 17/04/2024.
//

#ifndef CPPPROJECTCA2_GUI_H
#define CPPPROJECTCA2_GUI_H
#include <vector>
#include "Bug.h"
#include "Board.h"
#include "PlayerBug.h"
#include <SFML/Graphics.hpp>

class GUI {

private:
    Board& board;
    PlayerBug& playerBug;

public:
    GUI(Board &board, Bug &pb);
    void begin();
    static void draw(sf::RenderWindow &window, Bug& bug);
    bool checkForGameFinish();
};


#endif //CPPPROJECTCA2_GUI_H
