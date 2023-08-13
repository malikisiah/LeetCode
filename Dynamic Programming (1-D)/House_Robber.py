from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        prev, next = 0, 0

        for i in nums:
            temp = max(prev + i, next)
            prev = next
            next = temp

        return next
