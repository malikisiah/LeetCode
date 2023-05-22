from typing import List


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        result = []

        map = {}
        size = 0
        end = -1

        for i in range(len(s)):
            map[s[i]] = i

        for i in range(len(s)):
            size += 1

            if map[s[i]] > end:
                end = map[s[i]]
            if i == end:
                result.append(size)
                size = 0
        return result
