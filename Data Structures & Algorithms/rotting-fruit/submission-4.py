class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        fresh = 0
        rotten = deque()

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    fresh += 1
                if grid[r][c] == 2:
                    rotten.append((r, c))

        time = 0
        while rotten and fresh:
            for _ in range(len(rotten)):
                r, c = rotten.popleft()
                for dr, dc in ((0, 1), (-1, 0), (0, -1), (1, 0)):
                    nxr, nxc = r + dr, c + dc
                    if 0 <= nxr < ROWS and 0 <= nxc < COLS and grid[nxr][nxc] == 1:
                        rotten.append((nxr, nxc))
                        fresh -= 1
                        grid[nxr][nxc] = 2
            time += 1

        print(f'fresh: {fresh}, time: {time}')
        return time if fresh == 0 else -1

