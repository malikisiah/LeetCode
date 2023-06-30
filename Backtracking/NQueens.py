from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        cols = set()
        posDiag = set()  # (row + col)
        negDiag = set()  # (row - col)

        res = []

        board = [["."] * n for i in range(n)]

        def backtracking(row):
            if row == n:
                copy = ["".join(row) for row in board]
                res.append(copy)

            for col in range(n):
                if col in cols or (row + col) in posDiag or (row - col) in negDiag:
                    continue
                cols.add(col)
                posDiag.add(row + col)
                negDiag.add(row - col)
                board[row][col] = "Q"

                backtracking(row + 1)

                cols.remove(col)
                posDiag.remove(row + col)
                negDiag.remove(row - col)
                board[row][col] = "."

        backtracking(0)

        return res
