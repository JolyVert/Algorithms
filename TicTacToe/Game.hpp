#ifndef GAME_H
#define GAME_H

#include "Board.hpp"
#include "Player.hpp"
#include "AIPlayer.hpp"

class Game {
public:
    Game(int boardSize, int winLength);
    void playerMove(int row, int col);
    void aiMove();
    bool isOver() const;
    bool checkWin(Cell player) const;
    Cell getCell(int row, int col) const;
    void reset();

private:
    Board board;
    Player player;
    AIPlayer aiPlayer;
    Cell currentPlayer;
    bool gameOver;
};

#endif // GAME_H
