# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        # 1,null,3,4,null,null,5,null,null,
        if not root: return "n,"
        return str(root.val) + "," + self.serialize(root.left) + self.serialize(root.right)

    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        st, en = 0, 0

        def dfs() -> Optional[TreeNode]:
            nonlocal st, en, data
            while data[en] != ",": en += 1

            s = data[st:en]
            en += 1
            st = en

            if (s == "n"): return
            else: s = int(s)

            curr = TreeNode(s)
            curr.left = dfs()
            curr.right = dfs()
            
            return curr
        
        return dfs()
        

