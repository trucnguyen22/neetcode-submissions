class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0] * (n+2)

        dp[0] = 1
        def dfs(n):
            if n < 0:
                return 0
            print(n)
            if dp[n] != 0:
                return dp[n]

            dp[n] = dfs(n-1) + dfs(n-2)
            return dp[n]

        return dfs(n)
