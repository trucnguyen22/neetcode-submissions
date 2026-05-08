# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # preorder: root -> left -> right
        # inorder: left -> root -> right

        # 1. inorder give the amount of left and right nodes after found root
        # 2. use hashmap to optimize

        indices = {val : idx for idx, val in enumerate(inorder)}
        self.pre_idx = 0

        def dfs(l, r):
            if l > r: return

            root = TreeNode(preorder[self.pre_idx])
            self.pre_idx += 1
            mid = indices[root.val]

            root.left = dfs(l, mid - 1)
            root.right = dfs(mid + 1, r)

            return root
        
        return dfs(0, len(inorder) - 1)



        