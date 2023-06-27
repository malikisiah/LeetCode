from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        subset = []

        def dfs(i):
            if i >= len(nums):
                res.append(subset.copy())
                return

            # include element
            subset.append(nums[i])
            dfs(i + 1)

            # not include element
            subset.pop()
            dfs(i + 1)

        dfs(0)

        return res


nums = [1, 2, 3]
main = Solution()

main.subsets(nums)
