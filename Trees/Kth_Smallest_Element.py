from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        res = 0
        n = 0

        def inOrder(root):
            nonlocal res, n
            if not root:
                return

            inOrder(root.left)

            n += 1

            if n == k:
                res = root.val
                return

            inOrder(root.right)

        inOrder(root)
        return res
