from typing import List
from collections import defaultdict
import heapq


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        adj = defaultdict(list)  # node -> [(cost, node)]

        minHeap = [(0, 0)]  # (cost, node)

        for i in range(len(points)):
            x1, y1 = points[i]
            for j in range(i + 1, len(points)):
                x2, y2 = points[j]

                dist = abs(x1 - x2) + abs(y1 - y2)
                adj[i].append((dist, j))
                adj[j].append((dist, i))
        res = 0
        visit = set()

        while len(visit) < len(points):
            cost, node = heapq.heappop(minHeap)

            if node in visit:
                continue
            res += cost
            visit.add(node)

            for neiCost, j in adj[node]:
                if j not in visit:
                    heapq.heappush(minHeap, (neiCost, j))
        return res
