from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        row, col = len(board), len(board[0])

        def dfs(i, j):
            if i < 0 or j < 0 or i >= row or j >= col or board[i][j] != "O":
                return

            board[i][j] = "E"

            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        for c in range(col):
            dfs(0, c)
            dfs(row - 1, c)

        for r in range(row):
            dfs(r, 0)
            dfs(r, col - 1)

        for i in range(row):
            for j in range(col):
                if board[i][j] == "O":
                    board[i][j] = "X"
                if board[i][j] == "E":
                    board[i][j] = "O"
