class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ROW, COL = len(grid), len(grid[0])
        visited = [[0] * COL for _ in range(ROW)]

        def dfs(r, c):
            if r < 0 or r >= ROW or c < 0 or c >= COL or visited[r][c] == 1 or grid[r][c] == '0':
                return

            visited[r][c] = 1

            dfs(r+1, c)
            dfs(r-1, c)
            dfs(r, c+1)
            dfs(r, c-1)

        print(visited)
        island = 0
        for r in range(ROW):
            for c in range(COL):
                if grid[r][c] == '1' and not visited[r][c]:
                    island += 1
                    dfs(r, c)
        
        return island

