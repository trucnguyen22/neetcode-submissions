class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []

        cols, posDiags, negDiags = set(), set(), set()

        def dfs(r, subs):
            if r >= n:
                res.append(subs.copy())
                return

            curr = ""
            for c in range(n):
                if (c not in cols) and ((r-c) not in negDiags) and ((r+c) not in posDiags):
                    cols.add(c)
                    negDiags.add(r-c)
                    posDiags.add(r+c)

                    subs.append(curr + 'Q' + '.' * (n - c - 1))
                    dfs(r+1, subs)
                    subs.pop()

                    cols.remove(c)
                    negDiags.remove(r-c)
                    posDiags.remove(r+c)
                curr += '.'
        
        dfs(0, [])
        return res

