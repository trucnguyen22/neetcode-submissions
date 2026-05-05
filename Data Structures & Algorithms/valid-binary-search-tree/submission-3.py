# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        d = deque([(root, float("-inf"), float("inf"))])

        while d:
            root, left, right = d.popleft()
            if not (left < root.val < right):
                return False
            if root.left: d.append([root.left, left, root.val])
            if root.right: d.append([root.right, root.val, right])

        return True