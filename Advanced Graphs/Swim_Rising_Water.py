import heapq
from typing import List


def swimInWater(self, grid: List[List[int]]) -> int:
    minHeap = [[grid[0][0], (0, 0)]]  # [maxHeight, (x,y)]
    n = len(grid)
    visit = set()

    directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    while minHeap:
        height, cords = heapq.heappop(minHeap)

        if cords == (n - 1, n - 1):
            return height

        for dx, dy in directions:
            row = dx + cords[0]
            col = dy + cords[1]
            if row < 0 or col < 0 or row >= n or col >= n or (row, col) in visit:
                continue
            heapq.heappush(minHeap, [max(height, grid[row][col]), (row, col)])
            visit.add((row, col))
