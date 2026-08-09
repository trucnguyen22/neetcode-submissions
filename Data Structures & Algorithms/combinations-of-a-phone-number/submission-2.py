class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        m = {}
        m[2] = ['a', 'b', 'c']
        m[3] = ['d', 'e', 'f']
        m[4] = ['g', 'h', 'i']
        m[5] = ['j', 'k', 'l']
        m[6] = ['m', 'n', 'o']
        m[7] = ['p', 'q', 'r', 's']
        m[8] = ['t', 'u', 'v']
        m[9] = ['w', 'x', 'y', 'z']

        res = [""]
        for d in digits:
            tmp = []
            for sub in res:
                for c in m[int(d)]:
                    tmp.append(sub + c)
            res = tmp
        return res