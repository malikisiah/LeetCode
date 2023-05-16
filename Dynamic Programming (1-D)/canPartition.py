from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2 != 0:
            return False

        dp = set()
        dp.add(0)

        target = sum(nums) // 2

        for i in range(len(nums) - 1, -1, -1):
            new_dp = dp.copy()
            for num in dp:
                if nums[i] + num == target:
                    return True
                new_dp.add(nums[i] + num)

            dp = new_dp
        return False
