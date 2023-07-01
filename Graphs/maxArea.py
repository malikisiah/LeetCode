from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        globalMax = 0

        def dfs(i, j):
            if i < 0 or j < 0 or i >= row or j >= col or grid[i][j] != 1:
                return

            grid[i][j] = 0
            self.localMax += 1

            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    self.localMax = 0
                    dfs(i, j)
                    globalMax = max(globalMax, self.localMax)

        return globalMax
