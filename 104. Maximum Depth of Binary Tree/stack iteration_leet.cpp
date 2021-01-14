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

// TAIL RECURSION - recursive call is last action in function
// This algorithm works way differently. Just get smarter every day and eventually get there to do tremendous things. More syntax is known, easier it is to have room on mental stack to learn more complex things. More times you see a pattern, more it sinks in or becomes first thought. No chance of a thing being first thought if you haven't seen that pattern before. Practice promotes pattern perception
// ITERATION WITH STACK STRUCTURE ON HEAP
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return get_depth(root);
    }
    int get_depth(TreeNode* n){
        if (n==NULL) return 0;
        
        vector<pair<int, TreeNode*>> stack;  // dynamic array. Why did we choose a vector for our stack type?
        stack.push_back(pair<int, TreeNode*>(1,n));
        int max_depth = 0;
        while(!stack.empty()){
            pair<int, TreeNode*> current_pair = stack.back();
            int cur_depth = get<0>(current_pair);
            TreeNode* cur_node = get<1>(current_pair);
            max_depth = max(max_depth, cur_depth);
            stack.pop_back();
            if (cur_node->left !=NULL){
                stack.push_back(pair<int, TreeNode*>(cur_depth + 1, cur_node->left));
            } // left will get buried
            if (cur_node->right !=NULL){
                stack.push_back(pair<int, TreeNode*>(cur_depth + 1, cur_node->right));
            }
        }
        return max_depth;
    }
};
