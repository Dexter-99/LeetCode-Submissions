#include <iostream>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Iterative Approach;
class Solution
{
public:
  int rangeSumBST(TreeNode *root, int L, int R)
  {
    queue<TreeNode *> q;
    q.push(root);
    int sum = 0;
    while (!q.empty())
    {
      TreeNode *curr = q.front();
      q.pop();
      int nodeVal = curr->val;
      if (nodeVal >= L && nodeVal <= R)
        sum += nodeVal;
      if (curr->left != NULL)
        q.push(curr->left);
      if (curr->right != NULL)
        q.push(curr->right);
    }
    return sum;
  }
};