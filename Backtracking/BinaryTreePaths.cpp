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
  void dfs(TreeNode *root, vector<string> &ans, string curr)
  {
    if (root == NULL)
      return;

    if (!root->left && !root->right)
    {
      curr += to_string(root->val);
      ans.push_back(curr);
      return;
    }

    dfs(root->left, ans, curr + to_string(root->val) + "->");
    dfs(root->right, ans, curr + to_string(root->val) + "->");
    return;
  }
  vector<string> binaryTreePaths(TreeNode *root)
  {
    //         Simple DFS  O(2^n)
    vector<string> ans;
    dfs(root, ans, "");
    return ans;
  }
};