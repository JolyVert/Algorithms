#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Board.hpp"
#include "Minimax.hpp"

class AIPlayer {
public:
    AIPlayer(Cell symbol, const Board& board);
    std::pair<int, int> getBestMove(const Board& board);

private:
    Cell symbol;
    Minimax minimax;
};

#endif // AIPLAYER_H
