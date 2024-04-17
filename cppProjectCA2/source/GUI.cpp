//
// Created by seanm on 17/04/2024.
//

#include <SFML/Graphics.hpp>
#include "../headers/GUI.h"
#include "../headers/PlayerBug.h"

using namespace sf;

GUI::GUI(Board &board, Bug &pb) : board(board), playerBug(dynamic_cast<PlayerBug &>(pb)) {
    this->board = board;
    this->playerBug = dynamic_cast<PlayerBug &>(pb);
}

void GUI::draw(sf::RenderWindow &window,  Bug &bug) {
    sf::CircleShape shape;
    int radius = bug.getSize()*2;
    shape.setRadius(radius);
    if (bug.getBugType() == "Player"){
        shape.setFillColor(sf::Color::Red);
    } else if (bug.getBugType() == "Crawler") {
        shape.setFillColor(sf::Color::Black);
    }else if (bug.getBugType() == "Hopper") {
        shape.setFillColor(sf::Color::Blue);
    } else {
        shape.setFillColor(sf::Color::Magenta );
    }
    shape.setPosition((float(50 + (bug.getPosition().getY()) * 100)),
                      ((float) (50 + (bug.getPosition().getX()) * 100)));
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    window.draw(shape);
}

void GUI::begin() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    vector<sf::RectangleShape> boardGui;

    board.addNewBugToBoard(&playerBug);
    bool green = true;
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            sf::RectangleShape rect(sf::Vector2f(100, 100));
            rect.setPosition(x * 100, y * 100);
            if (green) {
                rect.setFillColor(sf::Color::Green);

            } else {
                rect.setFillColor(sf::Color::White);
            }
            green = !green;
            boardGui.push_back(rect);
        }
        green = !green;
    }


    PlayerBug playerRef = playerBug;

    bool keyIsPressed = false;
    bool gameFinished = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (!gameFinished && playerBug.isAlive()) {
            if (event.type == sf::Event::KeyPressed) {
                if (!keyIsPressed) {
                    if (event.key.code == sf::Keyboard::Left) {
                        playerBug.setDirection(Direction::West);
                    } else if (event.key.code == sf::Keyboard::Right) {
                        playerBug.setDirection(Direction::East);
                    } else if (event.key.code == sf::Keyboard::Up) {
                        playerBug.setDirection(Direction::North);
                    } else if (event.key.code == sf::Keyboard::Down) {
                        playerBug.setDirection(Direction::South);
                    }

                    if (!playerBug.isWayBlocked()){
                        board.tapBugBoard();
                    }

                    keyIsPressed = true;
                }
            } else if (event.type == sf::Event::KeyReleased) {
                keyIsPressed = false;
            }
        }

        gameFinished = checkForGameFinish();

        window.clear(sf::Color::White);
        for (sf::RectangleShape &rect: boardGui) {
            window.draw(rect);
        }
        for (Bug *b: board.getBugsVec()) {
            if (b->isAlive()) {
                draw(window, *b);
            }
        }
        window.display();
    }

}

bool GUI::checkForGameFinish() {
    int aliveCount = 0;
    for (int i=0;i<board.getBugsVec().size();i++){
        if (board.getBugsVec().at(i)->isAlive()){
            aliveCount++;
        }
    }
    if (aliveCount>1){
        return false;
    }
    return true;
}

