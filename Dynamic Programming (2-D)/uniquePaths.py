class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 1 and n == 1:
            return 1

        grid = [[0 for i in range(n)] for j in range(m)]

        # fill in last columns with 1's
        for i in range(0, m - 1):
            grid[i][n - 1] = 1

        # fill in last row with 1's
        for j in range(0, n - 1):
            grid[m - 1][j] = 1

        # count number of unique paths
        for i in range(m - 2, -1, -1):
            for j in range(n - 2, -1, -1):
                grid[i][j] = grid[i + 1][j] + grid[i][j + 1]

        for row in grid:
            print(row)

        return grid[0][0]
