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
  void solve(TreeNode *root, string curr, string &res)
  {
    if (root == NULL)
      return;
    if (root->left == NULL && root->right == NULL)
    {
      curr = (char)('a' + root->val) + curr;
      if (res == "" || curr < res)
      {
        res = curr;
      }
      return;
    }
    solve(root->left, (char)('a' + root->val) + curr, res);
    solve(root->right, (char)('a' + root->val) + curr, res);
  }
  string smallestFromLeaf(TreeNode *root)
  {
    string res = "";
    solve(root, "", res);
    return res;
  }
};