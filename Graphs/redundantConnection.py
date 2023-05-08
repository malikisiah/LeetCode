from typing import List


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parent = []
        rank = []

        for i in range(len(edges) + 1):
            parent.append(i)
            rank.append(1)

        def find(node) -> int:
            p = parent[node]

            while p != parent[p]:
                parent[p] = parent[parent[p]]
                p = parent[p]
            return p

        def union(node1, node2):
            p1 = find(node2)
            p2 = find(node2)

            if p1 == p2:
                return False

            if rank[p1] > rank[p2]:
                parent[p2] = p1
                rank[p1] += rank[p2]

            else:
                parent[p1] = p2
                rank[p2] += rank[p1]
            return True

        for n1, n2 in edges:
            if union(n1, n2) == False:
                return [n1, n2]
