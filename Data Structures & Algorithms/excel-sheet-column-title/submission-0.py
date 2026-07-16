class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        base = ord('A')
        c_map = {}
        s = ""

        for base in range(base, base+26):
            c_map[base] = chr(base)
        
        while (columnNumber > 0):
            columnNumber -= 1
            hash_c = columnNumber % 26
            columnNumber //= 26
            s += c_map[65 + hash_c]

        return s[::-1]
