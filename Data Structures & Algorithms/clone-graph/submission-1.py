"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        nodemap: Dict[int, Node] = {}

        def dfs(node):
            if node.val in nodemap:
                return nodemap[node.val]

            clone = Node(node.val)
            nodemap[node.val] = clone
            for nb in node.neighbors:
                clone.neighbors.append(dfs(nb))
            
            return clone
        
        if not node:
            return
        return dfs(node)
            
