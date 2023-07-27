from collections import defaultdict
from typing import List
import heapq


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = defaultdict(list)

        for u, v, w in times:
            adj[u].append((w, v))

        minHeap = [(0, k)]  # (cost, node)

        visit = set()

        longestPath = 0

        while minHeap:
            weight1, node1 = heapq.heappop(minHeap)

            if node1 in visit:
                continue
            visit.add(node1)
            longestPath = weight1

            for weight2, node2 in adj[node1]:
                if node2 not in visit:
                    heapq.heappush(minHeap, (weight1 + weight2, node2))
        return longestPath if len(visit) == n else -1
