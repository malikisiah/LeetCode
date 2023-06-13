from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        res = 0

        def dfs(root, currMax):
            nonlocal res

            if not root:
                return None

            if root.val >= currMax:
                res += 1

            dfs(root.left, max(currMax, root.val))
            dfs(root.right, max(currMax, root.val))

        dfs(root, root.val)
        return res
