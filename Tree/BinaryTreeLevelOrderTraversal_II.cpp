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
  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    vector<vector<int>> list;
    vector<int> res;
    queue<TreeNode *> q;
    if (root == NULL)
      return list;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
      TreeNode *curr = q.front();
      q.pop();
      if (curr == NULL)
      {
        list.push_back(res);
        res.clear();
        q.push(NULL);
        continue;
      }
      res.push_back(curr->val);
      if (curr->left != NULL)
        q.push(curr->left);
      if (curr->right != NULL)
        q.push(curr->right);
    }
    if (!res.empty())
      list.push_back(res);
    reverse(list.begin(), list.end());
    return list;
  }
};