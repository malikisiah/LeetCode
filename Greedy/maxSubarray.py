from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr = nums[0]
        result = nums[0]

        for i in range(1, len(nums)):
            curr = max(curr + nums[i], nums[i])
            result = max(curr, result)

        return result
