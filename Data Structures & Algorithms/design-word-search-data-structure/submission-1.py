class TrieNode:
    def __init__(self):
        self.child = {}
        self.word = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        cur = self.root
        for c in word:
            if c not in cur.child:
                cur.child[c] = TrieNode()
            cur = cur.child[c]
        cur.word = True

    def search(self, word: str) -> bool:
        def subtree(cur, j):
            for i in range(j, len(word)):
                c = word[i]
                if c == '.':
                    for nx in cur.child.values():
                        if subtree(nx, i+1):
                            return True
                    return False
                else:
                    if c not in cur.child:
                        return False
                    cur = cur.child[c]
            return cur.word
        return subtree(self.root, 0)
