class Solution:
    def countSubstrings(self, s: str) -> int:
        result = 0

        for i in range(len(s)):
            res += self.countPalindromes(s, i, i)
            res += self.countPalindromes(s, i, i + 1)

    def countPalindromes(s: str, l, r):
        while l >= 0 and r < len(s):
            res += 1
            l -= 1
            r += 1
