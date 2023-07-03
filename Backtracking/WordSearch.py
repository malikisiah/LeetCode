from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.row, self.col = len(board), len(board[0])
        path = set()

        def backtracking(i, j, index):
            if index == len(word):
                return True

            if (
                i < 0
                or j < 0
                or i >= self.row
                or j >= self.col
                or board[i][j] != word[index]
                or (i, j) in path
            ):
                return False

            path.add((i, j))

            if (
                backtracking(i + 1, j, index + 1)
                or backtracking(i - 1, j, index + 1)
                or backtracking(i, j + 1, index + 1)
                or backtracking(i, j - 1, index + 1)
            ):
                return True

            path.remove((i, j))

            return False

        for i in range(self.row):
            for j in range(self.col):
                if board[i][j] == word[0]:
                    if backtracking(i, j, 0) == True:
                        return True

        return False
