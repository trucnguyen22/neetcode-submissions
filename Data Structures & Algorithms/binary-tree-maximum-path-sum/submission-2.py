# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSum : int = float("-inf")
        
        def dfs(curr):
            nonlocal maxSum
            if not curr: return 0

            left_val = dfs(curr.left)
            right_val = dfs(curr.right)
            max_val = max(left_val, right_val)

            if max_val <= 0: s = curr.val
            else: s = max_val + curr.val

            maxSum = max(maxSum, max(s, left_val + right_val + curr.val))

            return s

        dfs(root)
        return maxSum


            