from collections import defaultdict
from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rowSet = defaultdict(set)
        colSet = defaultdict(set)
        gridSet = defaultdict(set)  # (row / 3, col / 3) -> visited Set

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == ".":
                    continue
                if (
                    board[i][j] in rowSet[i]
                    or board[i][j] in colSet[j]
                    or board[i][j] in gridSet[(i // 3, j // 3)]
                ):
                    return False
                rowSet[i].add(board[i][j])
                colSet[j].add(board[i][j])
                gridSet[(i // 3, j // 3)].add(board[i][j])

        return True
