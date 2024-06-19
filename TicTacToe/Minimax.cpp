#include "Minimax.hpp"
#include <limits>

Minimax::Minimax(Cell aiPlayer) : aiPlayer(aiPlayer), humanPlayer(aiPlayer == Cell::X ? Cell::O : Cell::X) {}

std::pair<int, int> Minimax::findBestMove(const Board& board) {
    int bestValue = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = { -1, -1 };

    for (int i = 0; i < board.getSize(); ++i) {
        for (int j = 0; j < board.getSize(); ++j) {
            if (board.getCell(i, j) == Cell::EMPTY) {
                Board newBoard = board;
                newBoard.makeMove(i, j, aiPlayer);
                int moveValue = minimax(newBoard, 0, false);
                if (moveValue > bestValue) {
                    bestMove = { i, j };
                    bestValue = moveValue;
                }
            }
        }
    }
    return bestMove;
}

int Minimax::minimax(Board& board, int depth, bool isMaximizing) {
    if (board.checkWin(aiPlayer)) {
        return 10;
    }
    if (board.checkWin(humanPlayer)) {
        return -10;
    }
    if (board.isFull()) {
        return 0;
    }

    int bestValue;
    if (isMaximizing) {
        bestValue = std::numeric_limits<int>::min();
        for (int i = 0; i < board.getSize(); ++i) {
            for (int j = 0; j < board.getSize(); ++j) {
                if (board.getCell(i, j) == Cell::EMPTY) {
                    board.makeMove(i, j, aiPlayer);
                    bestValue = std::max(bestValue, minimax(board, depth + 1, false));
                    board.makeMove(i, j, Cell::EMPTY);
                }
            }
        }
    }
    else {
        bestValue = std::numeric_limits<int>::max();
        for (int i = 0; i < board.getSize(); ++i) {
            for (int j = 0; j < board.getSize(); ++j) {
                if (board.getCell(i, j) == Cell::EMPTY) {
                    board.makeMove(i, j, humanPlayer);
                    bestValue = std::min(bestValue, minimax(board, depth + 1, true));
                    board.makeMove(i, j, Cell::EMPTY);
                }
            }
        }
    }
    return bestValue;
}

//int Minimax::evaluate(const Board& board) {
//    if (board.checkWin(aiPlayer)) {
//        return 10;
//    }
//    if (board.checkWin(humanPlayer)) {
//        return -10;
//    }
//    return 0;
//}
