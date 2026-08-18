class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = nums.copy()

        for i in range(1, len(nums)):
            if i == 1:
                dp[i] = max(dp[i], dp[i-1])
            else:
                dp[i] = max(dp[i] + dp[i-2], dp[i-1])

        return dp[len(nums)-1]