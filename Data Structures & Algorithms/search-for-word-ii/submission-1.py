class TrieNode:
    def __init__(self):
        self.idx = -1
        self.word = False
        self.child = {}

    def addword(self, word, idx):
        cur = self
        for c in word:
            if c not in cur.child:
                cur.child[c] = TrieNode()
            cur = cur.child[c]
        cur.word = True
        cur.idx = idx

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        ROWS, COLS = len(board), len(board[0])
        res, visit = set(), set()

        for idx, word in enumerate(words):
            root.addword(word, idx)

        def backtrack(r, c, nd_cur):
            nonlocal res, visit, ROWS, COLS
            if (r < 0 or c < 0 or r >= ROWS or c >= COLS or
                board[r][c] not in nd_cur.child or
                (r, c) in visit):
                return

            visit.add((r, c))
            nd_cur = nd_cur.child[board[r][c]]
            if (nd_cur.word):
                res.add(words[nd_cur.idx])
        
            backtrack(r - 1, c, nd_cur)
            backtrack(r + 1, c, nd_cur)
            backtrack(r, c - 1, nd_cur)
            backtrack(r, c + 1, nd_cur)
            visit.remove((r, c))
        
        for r in range(ROWS):
            for c in range(COLS):
                backtrack(r, c, root)
        
        return list(res)