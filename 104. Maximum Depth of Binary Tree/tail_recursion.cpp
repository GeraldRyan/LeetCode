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
class Solution
{
private:
  queue<pair<TreeNode *, int>> next_items; // declaring a next_items queue of type pair<pointer, int>
  // queue is a standard library container adapter // pair is an STL simple container consisting of two data elements.
  // Depth first non recursive uses stack; this queue contains next nodes to visit along with level/depth each node
  int max_depth = 0; //

  // tail recursion function
  int next_maxDepth()
  {
    if (next_items.size() == 0)
    { // always will be one originally because of root
      return max_depth;
    } // if no items are in the queue, max_depth is zero or whatever it is

    auto next_item = next_items.front();
    next_items.pop();

    auto next_node = next_item.first;       // property of pair template
    auto next_level = next_item.second + 1; // property of pair template

    max_depth = max(max_depth, next_level); // max depth is private variable of class. This changes private variable outside method. Always will be at least 1, or 1 + level

    // add nodes to visit in following recursive calls.
    if (next_node->left != NULL)
    {
      next_items.push(make_pair(next_node->left, next_level));
    }
    if (next_node->right != NULL)
    {
      next_items.push(make_pair(next_node->right, next_level));
    }

    // this last action should be only recursive call in entire function
    return next_maxDepth();
  }

public:
  int maxDepth(TreeNode *root)
  {
    return get_depth(root);
  }
  int get_depth(TreeNode *n)
  {
    if (n == NULL)
    {
      return 0;
    }
    // clear previous queue
    std::queue<pair<TreeNode *, int>> empty;
    std::swap(next_items, empty); // what about memory allocation?
    max_depth = 0;                // this max_depth is public..
    next_items.push(make_pair(n, 0));
    return next_maxDepth();
  }
};
