import math
from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low = 1
        high = max(piles)

        k = high

        def helper(k) -> int:
            sum = 0
            for i in piles:
                sum += math.ceil(i / k)

            return sum

        while low <= high:
            mid = low + (high - low) // 2

            if helper(mid) <= h:
                high = mid - 1
                k = min(k, mid)
            elif helper(mid) > h:
                low = mid + 1

        return k
