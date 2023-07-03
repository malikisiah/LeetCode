from typing import List


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        row, col = len(heights), len(heights[0])

        result = []
        atlantic = set()
        pacific = set()

        def dfs(i, j, visit, prevHeight):
            if (
                (i, j) in visit
                or i < 0
                or j < 0
                or i >= row
                or j >= col
                or heights[i][j] < prevHeight
            ):
                return
            visit.add((i, j))
            dfs(i + 1, j, visit, heights[i][j])
            dfs(i - 1, j, visit, heights[i][j])
            dfs(i, j + 1, visit, heights[i][j])
            dfs(i, j - 1, visit, heights[i][j])

        for c in range(col):
            dfs(0, c, pacific, heights[0][c])
            dfs(row - 1, c, atlantic, heights[row - 1][c])

        for r in range(row):
            dfs(r, 0, pacific, heights[r][0])
            dfs(r, col - 1, atlantic, heights[r][col - 1])

        for i in range(row):
            for j in range(col):
                if (i, j) in pacific and (i, j) in atlantic:
                    result.append([i, j])

        return result
