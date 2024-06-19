#include "Player.hpp"

Player::Player(Cell symbol) : symbol(symbol) {}

Cell Player::getSymbol() const {
    return symbol;
}
