from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(nums[0], self.helper(nums[1:]), self.helper(nums[:-1]))

    def helper(self, nums):
        prev, next = 0, 0

        for i in nums:
            maxVal = max(prev + i, next)
            prev = next
            next = maxVal
        return next
