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
  void solve(TreeNode *root, int &sum, int curr)
  {
    // cout<<curr<<endl;
    if (root == NULL)
      return;
    curr = curr * 10 + root->val;
    if (root->left == NULL && root->right == NULL)
    {
      sum += curr;
      return;
    }

    solve(root->left, sum, curr);
    solve(root->right, sum, curr);
  }
  int sumNumbers(TreeNode *root)
  {
    int sum = 0;
    solve(root, sum, 0);
    return sum;
  }
};