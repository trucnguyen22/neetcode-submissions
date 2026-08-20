class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        
        dp = [[0] * len(s) for _ in range(len(s))]

        # size-1 always a palindrome
        for i in range(len(s)):
            dp[i][i] = 1

        res = 1
        res_str = s[0]
        
        # size-n
        for size in range(2, len(s)+1):
            for i in range(0, len(s)-size+1):
                if s[i] == s[i+size-1] and (size <= 3 or dp[i+1][i+size-2] == 1):
                    dp[i][i+size-1] = 1
                    if size >= res:
                        res = size
                        res_str = s[i:i+size]
            
        return res_str