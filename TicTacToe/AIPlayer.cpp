#include "AIPlayer.hpp"

AIPlayer::AIPlayer(Cell symbol, const Board& board) : symbol(symbol), minimax(symbol) {}

std::pair<int, int> AIPlayer::getBestMove(const Board& board) {
    return minimax.findBestMove(board);
}
