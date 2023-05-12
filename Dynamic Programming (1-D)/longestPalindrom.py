class Solution:
    def longestPalindrome(self, s: str) -> str:
        result = ""
        maxLength = 0

        for i in range(len(s)):
            l = i
            r = i

            # odd length
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if (r - l + 1) > maxLength:
                    result = s[l : r + 1]
                    maxLength = r - l + 1
                r += 1
                l -= 1

            # even length

            l = i
            r = i + 1

            while l >= 0 and r < len(s) and s[l] == s[r]:
                if (r - l + 1) > maxLength:
                    result = s[l : r + 1]
                    maxLength = r - l + 1
                r += 1
                l -= 1

        return result
