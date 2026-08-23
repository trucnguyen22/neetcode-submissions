class Solution:
    def numDecodings(self, s: str) -> int:
        # dp_i = dp_i+1 || dp_i+2
        # 2611 = 2 | 611 + 26 | 11
        # 2611 = 611 11
        dp = [0] * len(s)

        def solve(i, sub):
            if i >= len(s):
                # print(sub)
                return 1

            if s[i] == '0':
                # print(sub, 'not acp')
                return 0
            
            if dp[i] != 0:
                return dp[i]

            # sub.append(s[i])
            single = solve(i+1, sub)
            # sub.pop()
            if (i+1<len(s) and (s[i]=='1' or (s[i]=='2' and s[i+1]<='6'))):
                # sub.append(s[i]+s[i+1])
                double = solve(i+2, sub)
                # sub.pop()
            else:
                double = 0

            dp[i] = single + double
            return dp[i]

        return solve(0, [])