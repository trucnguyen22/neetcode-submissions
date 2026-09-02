class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        # try to spread out from treasure (0-cell)
        ROWS, COLS = len(grid), len(grid[0])
        visited = [[0 for _ in range(COLS)] for _ in range(ROWS)]
        q = deque()

        def spread(r, c):
            if r < 0 or r == ROWS or c < 0 or c == COLS or grid[r][c] == -1 or visited[r][c]:
                return
            
            visited[r][c] = 1
            q.append((r, c))

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 0:
                    q.append((r, c))
                    visited[r][c] = 1

        d = 0
        while q:
            for _ in range(len(q)):
                r, c = q.popleft()
                grid[r][c] = d
                spread(r+1, c)
                spread(r, c+1)
                spread(r-1, c)
                spread(r, c-1)
            d += 1