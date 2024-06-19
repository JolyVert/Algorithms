#include "GUI.hpp"

GUI::GUI(int boardSize, int winLength)
    : window(sf::VideoMode(800, 800), "Tic Tac Toe"), game(boardSize, winLength), boardSize(boardSize) {
    cellSize = 800 / boardSize;
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(10, 10);
}

void GUI::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GUI::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            handlePlayerInput(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
        }
    }
}

void GUI::update() {
    if (game.isOver()) {
        if (game.checkWin(Cell::X)) {
            text.setString("Player X wins!");
        }
        else if (game.checkWin(Cell::O)) {
            text.setString("Player O wins!");
        }
        else {
            text.setString("It's a draw!");
        }
    }
    else {
        text.setString("");
    }
}

void GUI::render() {
    window.clear();

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            sf::RectangleShape cell(sf::Vector2f(cellSize - 2, cellSize - 2));
            cell.setPosition(i * cellSize, j * cellSize);
            cell.setFillColor(sf::Color::White);
            window.draw(cell);

            Cell cellValue = game.getCell(i, j);
            if (cellValue != Cell::EMPTY) {
                sf::Text symbol;
                symbol.setFont(font);
                symbol.setString(cellValue == Cell::X ? "X" : "O");
                symbol.setCharacterSize(cellSize - 10);
                symbol.setFillColor(sf::Color::Black);
                symbol.setPosition(i * cellSize + 10, j * cellSize + 10);
                window.draw(symbol);
            }
        }
    }

    window.draw(text);
    window.display();
}

void GUI::handlePlayerInput(sf::Mouse::Button button, int x, int y) {
    if (button == sf::Mouse::Left && !game.isOver()) {
        sf::Vector2i gridPos = getGridPosition(x, y);
        game.playerMove(gridPos.x, gridPos.y);
        if (!game.isOver()) {
            auto start = high_resolution_clock::now();
            game.aiMove();
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            std::cout << "Time taken to make move " << duration.count() << " microseconds" << std::endl;
        }
    }
}

sf::Vector2i GUI::getGridPosition(int x, int y) {
    return { x / cellSize, y / cellSize };
}
