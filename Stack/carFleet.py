from typing import List


class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pairs = []  # (pos, time)
        for i in range(len(position)):
            pairs.append((position[i], (target - position[i]) / speed[i]))

        pairs.sort()

        maxTime = 0.0
        res = 0

        for i in range(len(pairs) - 1, -1, -1):
            time = pairs[i][1]

            if time > maxTime:
                res += 1
                maxTime = time

        return res
