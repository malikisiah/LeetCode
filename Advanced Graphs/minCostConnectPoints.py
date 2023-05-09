from typing import List
import heapq


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        N = len(points)

        adj = {i: [] for i in range(N)}  # list of [cost,node]

        for i in range(N):
            x1, y1 = points[i]
            for j in range(i + 1, N):
                x2, y2 = points[j]
                dist = abs(x1 - x2) + abs(y1 - y2)
                adj[i].append([dist, j])
                adj[j].append([dist, i])

        res = 0
        visit = set()
        minHeap = [[0, 0]]  # [cost,point]

        while len(visit) < N:
            cost, i = heapq.heappop(minHeap)
            if i in visit:
                continue
            res += cost
            visit.add(i)

            for neighborCost, j in adj[i]:
                if j not in visit:
                    heapq.heappush(minHeap, [neighborCost, j])
        return res
