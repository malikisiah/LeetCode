from collections import defaultdict
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = defaultdict(int)
        freq = [[] for i in range(len(nums) + 1)]

        for i in nums:
            hashmap[i] += 1

        for num, count in hashmap.items():
            freq[count].append(num)

        result = []

        for i in range(len(freq) - 1, 0, -1):
            for j in freq[i]:
                result.append(j)
                if len(result) == k:
                    return result
