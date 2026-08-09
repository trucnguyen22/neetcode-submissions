class Solution:
    def partition(self, s: str) -> List[List[str]]:
        # s = "aab" -> first level = "a" "aa" "aab"

        res = []

        n = len(s)
        dp = [[False] * n for _ in range(n)]
        for j in range(n):
            for i in range(n):
                if (i+j >= n): continue
                dp[i][i+j] = (s[i] == s[i+j]) and (i+1 > i+j-1 or dp[i+1][i+j-1])
        
        def dfs(i, subs):
            if i >= len(s):
                res.append(subs.copy())
                return
            
            for j in range(i+1, len(s)+1):
                sub = s[i:j]
                if not dp[i][j-1]:
                    continue
                subs.append(sub)
                dfs(j, subs) 
                subs.pop()

        dfs(0, [])
        return res
        
