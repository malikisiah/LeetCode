from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float("inf")] * (amount + 1)

        dp[0] = 0

        for c in coins:
            for j in range(c, amount + 1):
                dp[j] = min(dp[j], dp[j - c] + 1)
        if dp[amount] != float("inf"):
            return dp[amount]
        else:
            return -1
