#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    vector<vector<int>> result;
    int rows = heights.size();
    int cols = heights[0].size();
    vector<vector<bool>> pacific(rows, vector<bool>(cols));
    vector<vector<bool>> atlantic(rows, vector<bool>(cols));

    for (int i = 0; i < rows; i++)
    {
        dfs(heights, pacific, i, 0, rows, cols);
        dfs(heights, atlantic, i, cols - 1, rows, cols);
    }

    for (int j = 0; j < cols; j++)
    {
        dfs(heights, pacific, 0, j, rows, cols);
        dfs(heights, atlantic, rows - 1, j, rows, cols);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (pacific[i][j] && atlantic[i][j])
            {
                result.push_back({i, j});
            }
        }
    }

    return result;
}

void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int i, int j, int row, int col)
{
    visited[i][j] = true;

    if (i > 0 && !visited[i - 1][j] && heights[i - 1][j] >= heights[i][j])
    {
        dfs(heights, visited, i - 1, j, row, col);
    }

    if (i < row - 1 && !visited[i + 1][j] && heights[i + 1][j] >= heights[i][j])
    {
        dfs(heights, visited, i + 1, j, row, col);
    }

    if (j > 0 && !visited[i][j - 1] && heights[i][j - 1] >= heights[i][j])
    {
        dfs(heights, visited, i, j - 1, row, col);
    }

    if (j < col - 1 && !visited[i][j + 1] && heights[i][j + 1] >= heights[i][j])
    {
        dfs(heights, visited, i, j + 1, row, col);
    }
}
