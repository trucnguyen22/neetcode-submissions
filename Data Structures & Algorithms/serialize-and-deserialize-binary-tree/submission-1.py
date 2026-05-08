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
        # preorder: Root -> Left -> Right
        if not root: return "n,"
        return str(root.val) + "," + self.serialize(root.left) + self.serialize(root.right)

    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        self.st = 0

        def dfs() -> Optional[TreeNode]:
            # extract value and update pt
            en = data.find(",", self.st)
            s = data[self.st:en]
            self.st = en + 1

            if (s == "n"): return

            curr = TreeNode(int(s))
            curr.left = dfs()
            curr.right = dfs()
            
            return curr
        
        return dfs()
        

