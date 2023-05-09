from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        result = []
        prev, next = 0, 0

        for i in range(len(nums)):
            result.append(max(prev + nums[i], next))
            prev = next
            next = result[i]
        print(result)
        return result[-1]


main = Solution()
main.rob([1, 2, 3, 1])
