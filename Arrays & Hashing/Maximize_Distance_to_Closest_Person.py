from typing import List


class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        prev = -1
        maxDist = 0

        for i in range(len(seats)):
            if seats[i] == 1:
                if prev == -1:
                    maxDist = i
                else:
                    dist = (i - prev) // 2
                    maxDist = max(dist, maxDist)
                prev = i

        dist = len(seats) - 1 - prev - i
        maxDist = max(maxDist, dist)

        return maxDist


main = Solution()
seats = [1, 0, 0, 0, 1, 0, 1]
main.maxDistToClosest(seats)
