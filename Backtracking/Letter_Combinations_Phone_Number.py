from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        digitsToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }
        res = []

        def backtracking(i, currStr):
            if len(currStr) == len(digits):
                res.append(currStr)
                return

            for c in digitsToChar[digits[i]]:
                backtracking(i + 1, currStr + c)

        if digits:
            backtracking(0, "")

        return res


main = Solution()
main.letterCombinations("23")
