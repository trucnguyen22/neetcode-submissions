# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # pre-order
        # curr
        # traversal(left)
        # traversal(right)

        # post-order
        # traversal(right)
        # traversal(left)
        # curr

        # in-order: 

        # level-order:
        arr = []
        ans = -1
        def inorder(root):
            nonlocal k, ans
            if (root == None): return
            if (root.left == None and root.right == None):
                k -= 1
                if k == 0: ans = root.val
                return
            inorder(root.left)
            if ans != -1: return
            k -= 1
            if k == 0: ans = root.val
            if ans != -1: return
            inorder(root.right)
            if ans != -1: return 

        inorder(root)
        return ans