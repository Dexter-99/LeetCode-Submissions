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
  int height(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }
  vector<vector<string>> printTree(TreeNode *root)
  {
    int h = height(root);
    int n = pow(2, h) - 1;
    vector<vector<string>> list(h, vector<string>(n, ""));
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, (n - 1) / 2}});
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        TreeNode *curr = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        // cout<<r<<" "<<c<<endl;
        list[r][c] = to_string(curr->val);
        if (curr->left)
        {
          q.push({curr->left, {r + 1, c - pow(2, h - r - 2)}});
        }
        if (curr->right)
        {
          q.push({curr->right, {r + 1, c + pow(2, h - r - 2)}});
        }
      }
    }
    return list;
  }
};