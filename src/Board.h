#pragma once

class Board
{
private:
    int m_Board[9 * 9];
public:
    Board() : m_Board{ 0 } {}
    const bool SetCell(int cellIdx, int value);
    const bool IsFree(int cellIdx, int value) const;
    const int* GetRow(int n) const;
    const int* GetCol(int n) const;
    const int* GetBox(int n) const;

private:
    static int BoxOf(int cellIdx);
};
