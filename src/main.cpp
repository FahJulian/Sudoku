#include <iostream>
#include "Board.h"

#define LOG(x) std::cout << x << std::endl;

int main()
{
    Board board;
    LOG(board.SetCell(0, 1));
    LOG(board.SetCell(0, 1));
    LOG(board.SetCell(10, 1));
    LOG(board.SetCell(1, 1));
    LOG(board.SetCell(19, 1));
    LOG(board.SetCell(12, 1));
}
