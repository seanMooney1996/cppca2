//
// Created by seanm on 17/04/2024.
//

#include <SFML/Graphics.hpp>
#include "../headers/GUI.h"

using namespace sf;
GUI::GUI(Board &board) : board(board) {
        this->board = board;
}

void GUI::draw(sf::RenderWindow &window,const Bug& bug) {
    sf::CircleShape shape;
    shape.setRadius(10);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(((float)(bug.getPosition().getX()))*100, ((float)(bug.getPosition().getY()))*100);
    window.draw(shape);
}

void GUI::begin() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    vector<sf::RectangleShape> boardGui;

    bool blk = true;
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            sf::RectangleShape rect(sf::Vector2f(100,100));
            rect.setPosition(x*100, y*100);
            if(blk)
            {
                rect.setFillColor(sf::Color::Green);

            }
            else
            {
                rect.setFillColor(sf::Color::White);
            }
            blk = !blk;
            boardGui.push_back(rect);
        }
        blk = !blk;
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            if(event.type == sf::Event::MouseButtonReleased) {
//                if (event.mouseButton.button == sf::Mouse::Left) {
//                    for(ball &b: balls) {
//                        b.move();
//                    }
//                }
//
//            }
//            if(event.type == sf::Event::KeyReleased)
//            {
//                cout << event.key.code << endl;
//                cout << sf::Keyboard::C << endl;
//                if(event.key.code == sf::Keyboard::Up)
//                {
//                    for(ball &b: balls) {
//                        b.move();
//                    }
//                }
//            }
        }
        window.clear(sf::Color::White);
        for(sf::RectangleShape &rect : boardGui)
        {
            window.draw(rect);
        }
        for(Bug *b: board.getBugsVec()) {

            draw(window,*b);
        }
        window.display();

    }

}

