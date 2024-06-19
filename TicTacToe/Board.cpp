#include "Board.hpp"

Board::Board(int size, int winLength) : size(size), winLength(winLength), grid(size, std::vector<Cell>(size, Cell::EMPTY)) {}

bool Board::makeMove(int row, int col, Cell player) {
    if (grid[row][col] == Cell::EMPTY) {
        grid[row][col] = player;
        return true;
    }
    return false;
}

bool Board::isFull() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell == Cell::EMPTY) {
                return false;
            }
        }
    }
    return true;
}

bool Board::checkWin(Cell player) const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] == player) {
                if (checkLine(i, j, 1, 0, player) || checkLine(i, j, 0, 1, player) ||
                    checkLine(i, j, 1, 1, player) || checkLine(i, j, 1, -1, player)) {
                    return true;
                }
            }
        }
    }
    return false;
}

Cell Board::getCell(int row, int col) const {
    return grid[row][col];
}

int Board::getSize() const {
    return size;
}

int Board::getWinLength() const {
    return winLength;
}

void Board::reset() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), Cell::EMPTY);
    }
}

bool Board::checkLine(int startRow, int startCol, int dRow, int dCol, Cell player) const {
    int count = 0;
    for (int i = 0; i < winLength; ++i) {
        int row = startRow + i * dRow;
        int col = startCol + i * dCol;
        if (row < 0 || row >= size || col < 0 || col >= size || grid[row][col] != player) {
            return false;
        }
        count++;
    }
    return count == winLength;
}
