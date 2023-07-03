from typing import List
import heapq
import math


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        minHeap = []  # (distance , [x , y])
        result = []

        # compute distance and add to minHeap
        for i in points:
            heapq.heappush(minHeap, (self.distance(i), i))

        for i in range(k):
            result.append(heapq.heappop(minHeap)[1])

        return result

    def distance(self, point):
        x = math.pow(point[0], 2)
        y = math.pow(point[1], 2)

        return math.sqrt(x + y)
