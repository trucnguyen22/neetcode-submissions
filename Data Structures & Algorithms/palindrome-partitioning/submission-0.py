class Solution:
    def partition(self, s: str) -> List[List[str]]:
        # s = "aab" -> first level = "a" "aa" "aab"

        res = []

        def check(s) -> bool:
            i = 0
            j = len(s)-1
            while i <= j:
                if s[i] != s[j]:
                    return False
                i += 1
                j -= 1
            return True

        def dfs(j, subs):
            if j >= len(s):
                res.append(subs.copy())
                return
            
            for i in range(j+1, len(s)+1):
                sub = s[j:i]
                if not check(sub):
                    continue
                subs.append(sub)
                dfs(i, subs) 
                subs.pop()

        dfs(0, [])
        return res
        
