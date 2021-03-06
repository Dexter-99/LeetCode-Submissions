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
class Solution
{
public:
  bool solve(TreeNode *root, int par)
  {
    if (root == NULL)
      return true;

    if (par == -1)
      return solve(root->left, root->val) && solve(root->right, root->val);
    return (root->val == par) && solve(root->left, root->val) && solve(root->right, root->val);
  }
  bool isUnivalTree(TreeNode *root)
  {
    return solve(root, -1);
  }
};