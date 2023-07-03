from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        curr = []

        def backtracking(i):
            if i >= len(s):
                res.append(curr.copy())
                return

            for j in range(i, len(s)):
                if self.isPalindrome(s[i : j + 1]):
                    curr.append(s[i : j + 1])
                    backtracking(j + 1)
                    curr.pop()

        backtracking(0)
        return res

    def isPalindrome(self, s):
        i = 0
        j = len(s) - 1

        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1

        return True
