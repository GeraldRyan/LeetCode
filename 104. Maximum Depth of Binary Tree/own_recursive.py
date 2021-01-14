# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def max(a, b):
    return a if a > b else b

class Solution:
    def get_depth(self, n):
        if (n == None):
            return 0;
        ldepth = self.get_depth(n.left)
        rdepth = self.get_depth(n.right)
        return 1 + max(ldepth, rdepth)
    def maxDepth(self, root: TreeNode) -> int:
        return self.get_depth(root);
        