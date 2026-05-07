# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # in-order traversal - recursive dfs
        # current node counted after left traversal
        # after find the 'kth' return any left recursion

        res: Treenode

        def dfs(curr):
            nonlocal res, k
            
            if not curr: return 

            dfs(curr.left) # delve left

            if k == 0: return 
            k -= 1
            if k == 0: 
                res = curr.val
                return
            
            dfs(curr.right) # delve right

        dfs(root)

        return res



