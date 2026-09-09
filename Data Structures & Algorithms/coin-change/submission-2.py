class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # am = min(am - c)
        # what if am - c < 0? 

        INF = 1e6
        dp = {}

        def solve(amount):
            if amount == 0:
                dp[amount] = 0
                return

            if amount in dp:
                return dp[amount]

            dp[amount] = INF
            for c in coins:
                if amount - c >= 0:
                    solve(amount - c)
                    dp[amount] = min(dp[amount], dp[amount-c]+1)

            return dp[amount]

        solve(amount)
        return -1 if dp[amount] == INF else dp[amount]
                        