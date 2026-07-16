class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # Convert binary strings to base-2 integers, add them, 
        # convert back to binary, and strip the '0b' prefix
        return bin(int(a, 2) + int(b, 2))[2:]