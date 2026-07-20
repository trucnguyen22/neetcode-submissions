import copy
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        memo = [[0] * len(triangle[r]) for r in range(len(triangle))]
        INF = float("inf")

        for r in range(len(triangle)):
            for c in range(len(triangle[r])):
                memo[r][c] = INF
        
        def dfs(row, col):
            if row >= len(triangle):
                return 0
            if memo[row][col] != INF:
                return memo[row][col]

            memo[row][col] = triangle[row][col] + min(
                dfs(row+1, col), dfs(row+1, col+1)
            )

            return memo[row][col]

        return dfs(0, 0)