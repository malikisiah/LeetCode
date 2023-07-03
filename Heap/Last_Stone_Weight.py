from typing import List
import heapq


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        maxHeap = []

        for i in stones:
            heapq.heappush(maxHeap, -i)

        while maxHeap:
            if len(maxHeap) == 1:
                return maxHeap[0] * -1

            x = heapq.heappop(maxHeap)
            y = heapq.heappop(maxHeap)

            if x != y:
                heapq.heappush(maxHeap, abs(y - x) * -1)

        return 0
