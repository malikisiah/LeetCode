#include <bits/stdc++.h>
using namespace std;
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    int maxArea = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {

                int currArea = 0;
                dfs(grid, i, j, row, col, currArea);

                maxArea = max(maxArea, currArea);
            }
        }
    }

    return maxArea;
}

void dfs(vector<vector<int>> &grid, int i, int j, int row, int col, int &result)
{
    if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0)
    {
        return;
    }

    grid[i][j] = 0;

    result++;

    dfs(grid, i + 1, j, row, col, result);
    dfs(grid, i - 1, j, row, col, result);
    dfs(grid, i, j + 1, row, col, result);
    dfs(grid, i, j - 1, row, col, result);
}