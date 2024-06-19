#ifndef BOARD_H
#define BOARD_H

#include <vector>

enum class Cell { EMPTY, X, O };

class Board {
public:
    Board(int size, int winLength);
    bool makeMove(int row, int col, Cell player);
    bool isFull() const;
    bool checkWin(Cell player) const;
    Cell getCell(int row, int col) const;
    int getSize() const;
    int getWinLength() const;
    void reset();

private:
    int size;
    int winLength;
    std::vector<std::vector<Cell>> grid;
    bool checkLine(int startRow, int startCol, int dRow, int dCol, Cell player) const;
};

#endif // BOARD_H
