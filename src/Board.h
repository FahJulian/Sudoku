#pragma once


class Board
{
private:
    int m_Data[9 * 9];
public:
    Board() : m_Data{ 0 } {}
    Board(int data[81]);

    const bool SetCell(int cellIdx, int value);
    bool Solve();
    void Print() const;

private:
    bool IsPossible(int cellIdx, int value) const;
    int NextEmptyCell() const;
    const int* GetRow(int n, int* row) const;
    const int* GetCol(int n, int* col) const;
    const int* GetBox(int n, int* box) const;

    static int BoxOf(int cellIdx);
};
