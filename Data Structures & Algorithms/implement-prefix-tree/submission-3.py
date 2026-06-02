class TrieNode:
    def __init__(self):
    # 1. A node contains 26 childs and endOfWord status
        self.child = {}
        self.endOfWord = False

class PrefixTree:
    # 1. Each node represents a character 
    #    and paths from the root to represent a word

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.child:
                curr.child[c] = TrieNode()
            curr = curr.child[c]
        curr.endOfWord = True

    def search(self, word: str) -> bool:
        curr = self.root
        for c in word:
            if c not in curr.child:
                return False
            curr = curr.child[c]
        return curr.endOfWord

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for c in prefix:
            if c not in curr.child:
                return False
            curr = curr.child[c]
        return True
        