#include "Game.hpp"

Game::Game(int boardSize, int winLength)
    : board(boardSize, winLength), player(Cell::X), aiPlayer(Cell::O, board), currentPlayer(Cell::X), gameOver(false) {}

void Game::playerMove(int row, int col) {
    if (!gameOver && board.makeMove(row, col, currentPlayer)) {
        if (board.checkWin(currentPlayer)) {
            gameOver = true;
        }
        else if (board.isFull()) {
            gameOver = true;
        }
        else {
            currentPlayer = currentPlayer == Cell::X ? Cell::O : Cell::X;
        }
    }
}

void Game::aiMove() {
    if (!gameOver) {
        auto move = aiPlayer.getBestMove(board);
        board.makeMove(move.first, move.second, currentPlayer);
        if (board.checkWin(currentPlayer)) {
            gameOver = true;
        }
        else if (board.isFull()) {
            gameOver = true;
        }
        else {
            currentPlayer = currentPlayer == Cell::X ? Cell::O : Cell::X;
        }
    }
}

bool Game::isOver() const {
    return gameOver;
}

bool Game::checkWin(Cell player) const {
    return board.checkWin(player);
}

Cell Game::getCell(int row, int col) const {
    return board.getCell(row, col);
}

void Game::reset() {
    board.reset();
    currentPlayer = Cell::X;
    gameOver = false;
}