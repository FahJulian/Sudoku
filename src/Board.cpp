#include "Board.h"
#include <iostream>

Board::Board(int data[81])
{
    for (int i = 0; i < 81; i++)
        m_Data[i] = data[i];
}

const bool Board::SetCell(int cellIdx, int value)
{
    if (!(value > 0 && value < 10) || !IsPossible(cellIdx, value)) 
        return false;
    
    std::cout << "Setting " << cellIdx << " to " << value << std::endl;
    m_Data[cellIdx] = value;
    return true;
}

const int* Board::GetRow(int n, int* row) const
{
    for (int i = 0; i < 9; i++)
        row[i] = m_Data[9 * n + i];

    return row;
}

const int* Board::GetCol(int n, int* col) const
{
    for (int i = 0; i < 9; i++)
        col[i] = m_Data[9 * i + n];

    return col;
}

const int* Board::GetBox(int n, int* box) const
{
    for (int i = 0; i < 9; i++)
        box[i] = m_Data[(n % 3) * 3 + (i % 3) + (n / 3) * 27 + (i / 3) * 9];
    
    return box;
}

bool Board::IsPossible(int cellIdx, int value) const
{
    if (value < 1 || value > 9) 
        return false;

    int row[9];
    GetRow(cellIdx / 9, row);
    int col[9];
    GetCol(cellIdx % 9, col);
    int box[9];
    GetBox(BoxOf(cellIdx), box);

    for (int i = 0; i < 9; i++)
        if (row[i] == value || col[i] == value || box[i] == value)
            return false;

    return true;
}

int Board::NextEmptyCell() const
{
    for (int i = 0; i < 9 * 9; i++)
    {
        if (i > 75 && m_Data[i] == 0)
            return i;
        if (m_Data[i] == 0)
            return i;
    }

    return -1;
}

bool Board::Solve()
{
    int nextEmptyCell = NextEmptyCell();
    if (nextEmptyCell == -1)    // Board is solved -> Stop recusion
        return true;

    for (int i = 1; i < 10; i++)
    {
        if (IsPossible(nextEmptyCell, i))
        {
            m_Data[nextEmptyCell] = i;
            if (Solve())
                return true;
        }
    }   

    m_Data[nextEmptyCell] = 0;
    return false;
}

void Board::Print() const
{
    for (int i = 0; i < 9 * 9; i++)
    {
        std::cout << m_Data[i];
        if ((i + 1) % 9 == 0)
            std::cout << std::endl;
    }
}

int Board::BoxOf(int cellIdx)
{
    int cellRow = (cellIdx / 9) / 3;
    int cellCol = (cellIdx % 9) / 3;
    return 3 * cellRow + cellCol;
}