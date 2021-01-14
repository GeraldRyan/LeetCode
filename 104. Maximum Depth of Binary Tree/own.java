
Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}


class Solution {
    public int maxDepth(TreeNode root) {
        return get_depth(root);
    }
    public int get_depth(TreeNode node){
        if (node == null){
            return 0;
        }
        int ldepth = get_depth(node.left);
        int rdepth = get_depth(node.right);
        return 1 + java.lang.Math.max(ldepth, rdepth);
    }
}