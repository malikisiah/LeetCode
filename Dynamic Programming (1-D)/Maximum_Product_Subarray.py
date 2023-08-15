from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        dp = [[float("inf"), float("-inf")]] * len(nums)
        dp[0] = [nums[0], nums[0]]
        result = nums[0]

        for i in range(1, len(nums)):
            maxProduct = max(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1], nums[i])
            minProduct = min(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1], nums[i])

            dp[i] = [maxProduct, minProduct]
            result = max(maxProduct, result)

        return result
