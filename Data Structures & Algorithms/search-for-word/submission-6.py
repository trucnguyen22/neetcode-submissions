class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        steps = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        ROW, COL = len(board), len(board[0])

        def inboard(r, c):
            return (r >= 0 and r < ROW) and (c >= 0 and c < COL)

        def search(r, c, i):
            nonlocal word
            if (board[r][c] == word[i]):
                print((r, c), 1)
                board[r][c] = '#'
            else:
                return False
            if i >= len(word) - 1:
                return True

            for s in steps:
                nx_r, nx_c = r + s[0], c + s[1]
                if (inboard(nx_r, nx_c) and (search(nx_r, nx_c, i+1))):
                    return True

            board[r][c] = word[i]
            return False
            
        for r in range(0, ROW):
            for c in range(0, COL):
                if search(r, c, 0):
                    return True
                print('=' * 10)
                print('\n')
        
        return False

                
            
