class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        memo = {}

        def dp(n, target):
            if n == 0:
                return 0 if target > 0 else 1

            if (n, target) in memo:
                return memo[(n, target)]

            result = 0

            for i in range(max(0, target - k), target):
                result += dp(n - 1, i)

            memo[(n, target)] = result
            return result

        return dp(n, target) % (10**9 + 7)


main = Solution()
n = 2
k = 6
target = 7

main.numRollsToTarget(n, k, target)
