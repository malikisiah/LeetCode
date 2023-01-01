#include <bits/stdc++.h>
using namespace std;

bool exist(vector<vector<char>> &board, string word)
{
    int row = board.size();
    int col = board[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (word[0] == board[i][j])
            {
                if (dfs(board, word, 0, i, j, row, col))
                {
                    return true;
                }
            }
        }
    }
}

bool dfs(vector<vector<char>> &board, string word, int idx, int i, int j, int row, int col)
{
    if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[idx])
    {
        return false;
    }

    if (idx == word.size() - 1)
    {
        return true;
    }

    board[i][j] = '#';

    if (dfs(board, word, idx + 1, i + 1, j, row, col) || dfs(board, word, idx + 1, i - 1, j, row, col) || dfs(board, word, idx + 1, i, j + 1, row, col) || dfs(board, word, idx + 1, i, j - 1, row, col))
    {
        return true;
    }

    board[i][j] = word[idx];

    return false;
}