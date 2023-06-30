from typing import List


class TrieNode:
    def __init__(self) -> None:
        self.children = {}
        self.isWord = {}

    def addWord(self, word):
        curr = self

        for i in word:
            if i not in curr.children:
                curr.children[i] = TrieNode()
            curr = curr.children[i]

        curr.isWord = True


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        row, col = len(board), len(board[0])
        root = TrieNode()

        for word in words:
            root.addWord(word)

        result, visit = set(), set()

        def dfs(i, j, node, word):
            if (
                i < 0
                or j < 0
                or i >= row
                or j >= col
                or board[i][j] not in node.children
                or (i, j) in visit
            ):
                return False

            visit.add((i, j))
            node = node.children[board[i][j]]
            word += board[i][j]

            if node.isWord:
                result.add(word)
                node.isWord = False

            dfs(i + 1, j, node, word)
            dfs(i - 1, j, node, word)
            dfs(i, j + 1, node, word)
            dfs(i, j - 1, node, word)

            visit.remove((i, j))

        for i in range(row):
            for j in range(col):
                dfs(i, j, root, "")

        return list(result)
