#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{

    queue<pair<int, int>> q;
    int m = grid.size();
    int n = grid[0].size();

    int freshOranges = 0;
    int result = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                freshOranges++;
            }
        }
    }

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty() && freshOranges > 0)
    {

        int len = q.size();

        for (int i = 0; i < q.size(); i++)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int j = 0; j < directions.size(); j++)
            {
                int x = row + directions[j][0];
                int y = col + directions[j][1];

                if (x < 0 || x >= m || y < 0 || y >= n)
                {
                    continue;
                }

                if (grid[x][y] == 1)
                {
                    grid[x][y] = 2;
                    freshOranges--;
                    q.push({x, y});
                }
            }
        }

        result++;
    }

    if (freshOranges == 0)
    {
        return result;
    }
    return -1;
}
