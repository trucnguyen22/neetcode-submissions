class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ROW, COL = len(grid), len(grid[0])
        direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        visited = [[0] * COL for _ in range(ROW)]


        def dfs(r, c) -> int:
            if r < 0 or r >= ROW or c < 0 or c >= COL or visited[r][c] == 1 or grid[r][c] == 0:
                return 0
            
            visited[r][c] = 1

            nx_area = 0
            for rd, cd in direction:
                nx_area += dfs(r+rd, c+cd)

            return 1 + nx_area


        mx_area = 0
        for r in range(ROW):
            for c in range(COL):
                if grid[r][c] == 1 and not visited[r][c]:
                    mx_area = max(mx_area, dfs(r, c))

        return mx_area
