#ifndef MINIMAX_H
#define MINIMAX_H

#include "Board.hpp"

class Minimax {
public:
    explicit Minimax(Cell aiPlayer);
    std::pair<int, int> findBestMove(const Board& board);

private:
    int minimax(Board& board, int depth, bool isMaximizing);
    //int evaluate(const Board& board);
    Cell aiPlayer;
    Cell humanPlayer;
};

#endif // MINIMAX_H
