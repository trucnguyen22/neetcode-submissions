class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # i'm trying go from higher cells
        # fit: try to go from the ocean first, then bfs to higher_or_equal cells

        ROWS, COLS = len(heights), len(heights[0])

        def bfs(starts):
            seen = set(starts)
            stack = list(starts)

            while stack:
                r, c = stack.pop()
                for dr, dc in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                    nxr, nxc = r + dr, c + dc
                    if 0 <= nxr < ROWS and 0 <= nxc < COLS and (nxr, nxc) not in seen and heights[nxr][nxc] >= heights[r][c]:
                        stack.append((nxr, nxc))
                        seen.add((nxr, nxc))
            
            return seen
        
        pacific = bfs([(0, c) for c in range(COLS)] + [(r, 0) for r in range(ROWS)])
        atlantic = bfs([(ROWS-1, c) for c in range(COLS)] + [(r, COLS-1) for r in range(ROWS)])

        return [list(cell) for cell in pacific & atlantic]
