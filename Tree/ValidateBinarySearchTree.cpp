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
  bool solve(TreeNode *root, long long _min, long _max)
  {
    if (root == NULL)
      return true;
    else if (root->val <= _min || root->val >= _max)
    {

      return false;
    }
    return solve(root->left, _min, root->val) && solve(root->right, root->val, _max);
  }
  bool isValidBST(TreeNode *root)
  {

    long long _min = INT64_MIN;
    long long _max = INT64_MAX;
    return solve(root, _min, _max);
  }
};