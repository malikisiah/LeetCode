import heapq
import collections
from typing import List


class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, k: int
    ) -> int:
        edges = collections.defaultdict(list)

        for f, t, p in flights:
            edges[f].append((t, p))

        minHeap = [(0, src, -1)]  # (cost, node, stops)

        minCost = {}  # (node, stops) : cost

        while minHeap:
            w1, n1, stops = heapq.heappop(minHeap)

            if n1 == dst and stops <= k:
                return w1

            if stops < k:
                for n2, w2 in edges[n1]:
                    totalCost = w1 + w2

                    if (n2, stops + 1) not in minCost or totalCost < minCost[
                        n2, stops + 1
                    ]:
                        minCost[n2, stops + 1] = totalCost
                        heapq.heappush(minHeap, (totalCost, n2, stops + 1))
        return -1
