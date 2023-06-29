from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        curr = []
        candidates.sort()

        def backtracking(i, total):
            if total > target:
                return

            if total == target:
                res.append(curr.copy())
                return

            for j in range(i, len(candidates)):
                # skip duplicates
                if j > i and candidates[j] == candidates[j - 1]:
                    continue

                if total + candidates[j] > target:
                    break

                curr.append(candidates[j])
                # pass j + 1 to the next level to avoid using the same number again
                backtracking(j + 1, total + candidates[j])
                curr.pop()

        backtracking(0, 0)

        return res
