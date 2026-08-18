class Solution:
    def rob(self, nums: List[int]) -> int:
        # dp[n][1] includes house#1
        dp = [[0] * len(nums) for _ in range(2)] 

        n = len(nums)
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
        
        # print(n)
        dp[1][1] = max(nums[0], nums[1])
        dp[0][1] = nums[1]
        dp[0][2] = max(nums[1], nums[2])
        if n > 3:
            dp[1][2] = max(nums[1], nums[2]+nums[0])
        else:
            dp[1][2] = nums[1]

        for i in range(3, len(nums)):
            dp[0][i] = max(dp[0][i-2] + nums[i], dp[0][i-1])
            if i == len(nums)-1:
                dp[1][i] = dp[1][i-1]
            else:
                dp[1][i] = max(dp[1][i-2] + nums[i], dp[1][i-1])

        return max(dp[0][n-1], dp[1][n-1])