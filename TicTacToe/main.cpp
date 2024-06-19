#include "Game.hpp"
#include "GUI.hpp"
#include <iostream>

int main() {
    int boardSize, winLength;

    std::cout << "Ennnnter board size: ";
    std::cin >> boardSize;

    std::cout << "Enter win length: ";
    std::cin >> winLength;

    GUI gui(boardSize, winLength);
    gui.run();
    return 0;
}
