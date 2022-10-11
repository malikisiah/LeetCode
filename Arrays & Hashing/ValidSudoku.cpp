#include <bits/stdc++.h>
using namespace std;

bool checkSubSection(int idxI, int idxJ, vector<vector<char>> &board);

bool isValidSudoku(vector<vector<char>> &board)
{
    int rows = board.size();
    int cols = board[0].size();

    // checking rows;
    for (int i = 0; i < rows; i++)
    {
        unordered_set<char> rowSet;
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }

            if (rowSet.find(board[i][j]) != rowSet.end())
            {
                return false;
            }
            rowSet.insert(board[i][j]);
        }
    }
    // checking columns
    for (int i = 0; i < cols; i++)
    {
        unordered_set<char> colSet;
        for (int j = 0; j < rows; j++)
        {
            if (board[j][i] == '.')
            {
                continue;
            }

            if (colSet.find(board[j][i]) != colSet.end())
            {
                return false;
            }
            colSet.insert(board[j][i]);
        }
    }

    // check sub-sections
    for (int i = 0; i < rows; i += 3)
    {
        for (int j = 0; j < cols; j += 3)
        {
            if (!checkSubSection(i, j, board))
            {
                return false;
            }
        }
    }

    return true;
}

bool checkSubSection(int idxI, int idxJ, vector<vector<char>> &board)
{
    int rows = idxI + 3;
    int cols = idxJ + 3;

    unordered_set<char> subSet;

    for (int i = idxI; i < rows; i++)
    {
        for (int j = idxJ; j < cols; j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }
            if (subSet.find(board[i][j]) != subSet.end())
            {
                return false;
            }
            subSet.insert(board[i][j]);
        }
    }

    return true;
}