from collections import defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strs_sorted = []

        for i in strs:
            strs_sorted.append("".join(sorted(i)))

        map = defaultdict(list)

        for i in range(len(strs)):
            map[strs_sorted[i]].append(strs[i])

        result = []

        for i in map:
            result.append(map[i])

        return result
