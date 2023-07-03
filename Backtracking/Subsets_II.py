from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []

        nums.sort()

        subset = []

        def backtracking(i):
            if i >= len(nums):
                res.append(subset.copy())
                return

            subset.append(nums[i])
            backtracking(i + 1)

            subset.pop()

            while i + 1 < len(nums) and nums[i] == nums[i + 1]:
                i += 1
            backtracking(i + 1)

        backtracking(0)
        return res
