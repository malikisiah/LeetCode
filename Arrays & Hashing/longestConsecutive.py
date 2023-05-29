from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hashset = set(nums)
        result = 0

        for i in nums:
            if (i - 1) not in hashset:
                length = 0
                while (i + length) in hashset:
                    length += 1
                result = max(length, result)

        return result
