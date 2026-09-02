class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        INF = 2147483647
        ROWS, COLS = len(grid), len(grid[0])
        R1, C1 = ROWS - 1, COLS - 1

        frontier = []
        for r in range(ROWS):
            row = grid[r]
            for c in range(COLS):
                if row[c] == 0:
                    frontier.append((r, c))

        d = 0
        while frontier:
            d += 1
            nxt = []
            push = nxt.append
            for r, c in frontier:
                row = grid[r]
                if r and grid[r-1][c] == INF:
                    grid[r-1][c] = d
                    push((r-1, c))
                if r < R1 and grid[r+1][c] == INF:
                    grid[r+1][c] = d
                    push((r+1, c))
                if c and row[c-1] == INF:
                    row[c-1] = d
                    push((r, c-1))
                if c < C1 and row[c+1] == INF:
                    row[c+1] = d
                    push((r, c+1))
            frontier = nxt