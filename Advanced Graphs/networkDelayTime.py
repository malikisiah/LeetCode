import collections
from typing import List
import heapq


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = collections.defaultdict(list)

        for u, v, w in times:
            edges[u].append((v, w))

        visit = set()
        longestPath = 0
        minHeap = [(0, k)]  # weight goes first to always find minimum

        while minHeap:
            weight1, node1 = heapq.heappop(minHeap)
            if node1 in visit:
                continue
            visit.add(node1)
            longestPath = weight1

            for node2, weight2 in edges[node1]:
                if node2 not in visit:
                    heapq.heappush(minHeap, (weight1 + weight2, node2))
        if len(visit) == n:
            return longestPath
        else:
            return -1
