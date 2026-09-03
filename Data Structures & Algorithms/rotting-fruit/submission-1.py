class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        fresh = 0
        rotten = deque()
        visited = [[0 for _ in range(COLS)] for _ in range(ROWS)]

        def search(r, c):
            nonlocal fresh
            if min(r, c) < 0 or r == ROWS or c == COLS or visited[r][c] or grid[r][c] == 0:
                return
            
            if grid[r][c] == 1:
                fresh -= 1
            visited[r][c] = 1
            rotten.append((r, c))

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    fresh += 1
                if grid[r][c] == 2:
                    rotten.append((r, c))
                    visited[r][c] = 1

        time = 0
        while rotten:
            for _ in range(len(rotten)):
                r, c = rotten.popleft()
                search(r+1, c)
                search(r, c+1)
                search(r-1, c)
                search(r, c-1)
            time += 1
        time = time-1 if time > 0 else 0

        print(f'fresh: {fresh}, time: {time}')
        return time if fresh == 0 else -1