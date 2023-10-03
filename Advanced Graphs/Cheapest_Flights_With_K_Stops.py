from typing import List
from collections import defaultdict
import heapq


class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, k: int
    ) -> int:
        adj = defaultdict(list)  # node -> [(neighbor, cost)]

        for node, neighbor, cost in flights:
            adj[node].append((neighbor, cost))

        minHeap = [(0, src, -1)]  # (cost, node, stops)

        minCost = {}  # (node,stops) -> cost

        for key, value in adj.items():
            print(f"{key} | {value}")

        while minHeap:
            weight, node, stops = heapq.heappop(minHeap)

            if node == dst and stops <= k:
                return weight

            if stops < k:
                for neighbor, cost in adj[node]:
                    total = cost + weight

                    if (neighbor, stops + 1) not in minCost or total < minCost[
                        neighbor, stops + 1
                    ]:
                        minCost[neighbor, stops + 1] = total
                        heapq.heappush(minHeap, (total, neighbor, stops + 1))

        return -1
