from typing import Optional


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:
    def serialize(self, root):
        res = []

        def dfs(node):
            if not node:
                res.append("null")
                return

            res.append(str(node.val))
            dfs(node.left)
            dfs(node.right)

        dfs(root)
        return ",".join(res)

        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """

    def deserialize(self, data):
        values = data.split(",")
        self.i = 0

        def dfs():
            if values[self.i] == "null":
                self.i += 1
                return None
            node = TreeNode(int(values[self.i]))
            self.i += 1
            node.left = dfs()
            node.right = dfs()

            return node

        return dfs()
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
