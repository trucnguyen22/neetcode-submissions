class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        m = {}
        m[2] = ['a', 'b', 'c']
        m[3] = ['d', 'e', 'f']
        m[4] = ['g', 'h', 'i']
        m[5] = ['j', 'k', 'l']
        m[6] = ['m', 'n', 'o']
        m[7] = ['p', 'q', 'r', 's']
        m[8] = ['t', 'u', 'v']
        m[9] = ['w', 'x', 'y', 'z']

        res = []
        def dfs(i, sub):
            if i >= len(digits):
                if (len(sub) > 0): 
                    res.append("".join(sub.copy()))
                return

            chars = m[int(digits[i])]
            for c in chars:
                sub.append(c)
                dfs(i+1, sub)
                sub.pop() 

        dfs(0, [])
        return res