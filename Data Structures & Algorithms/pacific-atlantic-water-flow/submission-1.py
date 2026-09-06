class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        ROWS, COLS = len(heights), len(heights[0])

        visited = [[0 for _ in range(COLS)] for _ in range(ROWS)]
        pa, at = set(), set()
        res = []

        for r in range(ROWS):
            for c in range(COLS):
                if r == 0:
                    pa.add((r, c))
                if c == 0:
                    pa.add((r, c))
                if r == ROWS-1:
                    at.add((r, c))
                if c == COLS-1:
                    at.add((r, c))
        
        def bfs(r, c):
            q = deque()

            q.append((r, c))
            while(q):
                for _ in range(len(q)):
                    r, c = q.popleft()
                    visited[r][c] = 1
                    for dr, dc in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                        nxr, nxc = r + dr, c + dc
                        if 0 <= nxr < ROWS and 0 <= nxc < COLS and heights[r][c] >= heights[nxr][nxc]:
                            if not visited[nxr][nxc]:
                                bfs(nxr, nxc)
                            if (nxr, nxc) in pa:
                                pa.add((r, c))
                            if (nxr, nxc) in at:
                                at.add((r, c))
                
        for r in range(ROWS):
            for c in range(COLS):
                bfs(r, c)
                if (r, c) in pa and (r, c) in at:
                    res.append([r, c])
        return res     