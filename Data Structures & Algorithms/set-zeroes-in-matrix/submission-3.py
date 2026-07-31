class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        # matrix=[[1,2,3,4],
                # [5,0,7,8],
                # [0,10,11,12],
                # [13,14,15,0]]
        # [[1,0,3,4],[0,0,0,0],[0,0,11,0],[0,0,0,0]]
        # [[0,0,3,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
        ROW, COL = len(matrix), len(matrix[0])
        trace = {}
        def search(r, c, direction):
            if (r < 0 or r >= ROW or c < 0 or c >= COL):
                return
            
            if (matrix[r][c] != 0): trace[(r, c)] = True
            matrix[r][c] = 0
            search(r+direction[0], c+direction[1], direction)
        
        for r in range(ROW):
            for c in range(COL):
                if matrix[r][c] == 0 and ((r, c) not in trace):
                    search(r-1, c, (-1, 0))
                    search(r+1, c, (1, 0))
                    search(r, c-1, (0, -1))
                    search(r, c+1, (0, 1))
        