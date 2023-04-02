#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>> &board)
{
    int rows = board.size();
    int cols = board[0].size();

    // marking escaped cells along top and bottom border
    for (int i = 0; i < rows; i++)
    {
        dfs(board, rows, cols, i, 0);
        dfs(board, rows, cols, i, cols - 1);
    }

    // marking escaped cells along left and right border
    for (int j = 0; j < cols; j++)
    {
        dfs(board, rows, cols, 0, j);
        dfs(board, rows, cols, rows - 1, j);
    }

    // flipping cells to correct final states
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }

            if (board[i][j] == 'E')
            {
                board[i][j] = 'O';
            }
        }
    }
}

void dfs(vector<vector<char>> &board, int rows, int cols, int i, int j)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O')
    {
        return;
    }

    board[i][j] = 'E';

    dfs(board, rows, cols, i - 1, j);
    dfs(board, rows, cols, i + 1, j);
    dfs(board, rows, cols, i, j - 1);
    dfs(board, rows, cols, i, j + 1);
}