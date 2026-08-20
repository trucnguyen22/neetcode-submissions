class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        
        dp = [[0] * len(s) for _ in range(len(s))]

        res = 0
        res_str = ""
        # size-1 always a palindrome
        for i in range(len(s)-1, -1, -1):
            for j in range(i, len(s)):
                if (s[i] == s[j]) and (j-i <= 2 or dp[i+1][j-1] == 1):
                    dp[i][j] = 1
                    if (j-i+1 > res):
                        res = j-i+1
                        res_str = s[i:j+1]

        return res_str