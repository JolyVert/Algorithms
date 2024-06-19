#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include "Game.hpp"

using namespace std::chrono;

class GUI {
public:
    GUI(int boardSize, int winLength);
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handlePlayerInput(sf::Mouse::Button button, int x, int y);
    sf::Vector2i getGridPosition(int x, int y);

    sf::RenderWindow window;
    Game game;
    int cellSize;
    int boardSize;
    sf::Font font;
    sf::Text text;
};

#endif // GUI_H
