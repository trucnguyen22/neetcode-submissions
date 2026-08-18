class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0] * (n+1)

        def dfs(n):
            if n < 0:
                return 0
            if dp[n] != 0:
                return dp[n]

            if n == len(cost):
                dp[n] = min(dfs(n-1), dfs(n-2))
            else:
                dp[n] = cost[n] + min(dfs(n-1), dfs(n-2))
            
            print(dp[n])
            return dp[n]

        return dfs(n)