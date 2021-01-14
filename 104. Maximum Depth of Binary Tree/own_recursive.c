#include <stdio.h>

// RECURSIVE SOLUTION O(n^2) I think. 

Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


#define max(a,b) (((a) > (b)) ? a : b)

int get_depth(struct TreeNode* n){
    int trial_depth = 0;
    if (n == NULL){
    return 0;
    }
    int ldepth = get_depth(n->left);
    int rdepth = get_depth(n->right);
    
    return 1 + max(ldepth, rdepth);
}

int maxDepth(struct TreeNode* root){
   return get_depth(root);

}