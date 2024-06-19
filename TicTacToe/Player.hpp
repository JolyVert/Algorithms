#ifndef PLAYER_H
#define PLAYER_H

#include "Board.hpp"

class Player {
public:
    explicit Player(Cell symbol);
    Cell getSymbol() const;

private:
    Cell symbol;
};

#endif // PLAYER_H
