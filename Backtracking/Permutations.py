from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def backtrack(nums, perm):
            if not nums:
                res.append(perm)
                return
            for i in range(len(nums)):
                backtrack(nums[:i] + nums[i + 1 :], perm + [nums[i]])

        backtrack(nums, [])
        return res
