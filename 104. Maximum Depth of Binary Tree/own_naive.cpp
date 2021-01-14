#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// BASIC RECURSION THAT MIGHT OVERFLOW THE STACK
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return get_depth(root);
        
    }
    int get_depth(TreeNode* n){
        if (n == NULL){
            return 0;
        }
        int ldepth = get_depth(n->left);
        int rdepth = get_depth(n->right);
        return 1 + max(ldepth, rdepth);
    }
};