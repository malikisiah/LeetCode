class Solution(object):
    def isInterleave(self, s1, s2, s3):
        if len(s1) + len(s2) != len(s3):
            return False

        n = len(s1)
        m = len(s2)

        dp = [[False] * (len(s2) + 1) for i in range(len(s1) + 1)]

        dp[n][m] = True

        for i in range(n, -1, -1):
            for j in range(m, -1, -1):
                if i < n and s1[i] == s3[i + j] and dp[i + 1][j]:
                    dp[i][j] = True
                if j < m and s2[j] == s3[i + j] and dp[i][j + 1]:
                    dp[i][j] = True
        return dp[0][0]
