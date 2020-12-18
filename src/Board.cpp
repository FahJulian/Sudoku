#include "Board.h"

const bool Board::SetCell(int cellIdx, int value)
{
    if (!(value > 0 && value < 10) || !IsFree(cellIdx, value)) 
        return false;
    
    m_Board[cellIdx] = value;
    return true;
}

const int* Board::GetRow(int n) const
{
    int* row = new int[9];
    for (int i = 0; i < 9; i++)
        row[i] = m_Board[9 * n + i];

    return row;
}

const int* Board::GetCol(int n) const
{
    int* col = new int[9];
    for (int i = 0; i < 9; i++)
        col[i] = m_Board[9 * i + n];

    return col;
}

const int* Board::GetBox(int n) const
{
    int* cell = new int[9];
    for (int i = 0; i < 9; i++)
        cell[i] = m_Board[(n % 3) * 3 + (i % 3) + (n / 3) * 3 + (i / 3)];
    
    return cell;
}

const bool Board::IsFree(int cellIdx, int value) const
{
    const int* row = GetRow(cellIdx / 9);
    const int* col = GetCol(cellIdx % 9);
    const int* cell = GetBox(BoxOf(cellIdx));

    bool correct = true;
    for (int i = 0; i < 9; i++)
    {
        if (*(row + i) == value || *(col + i) == value || *(cell + i) == value)
        {
            correct = false;
            break;
        }
    }

    delete[] row;
    delete[] col;
    delete[] cell;
    return correct;
}

int Board::BoxOf(int cellIdx)
{
    int cellRow = (cellIdx / 9) / 3;
    int cellCol = (cellIdx % 9) / 3;
    return 3 * cellRow + cellCol;
}
