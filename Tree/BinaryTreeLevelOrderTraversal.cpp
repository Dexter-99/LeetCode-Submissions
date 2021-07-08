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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> list;
    if (root == NULL)
      return list;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      int size = q.size();
      vector<int> res(size, 0);
      for (int i = 0; i < size; i++)
      {
        TreeNode *curr = q.front();
        q.pop();
        res[i] = (curr->val);
        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }
      list.push_back(res);
    }
    return list;
  }
};