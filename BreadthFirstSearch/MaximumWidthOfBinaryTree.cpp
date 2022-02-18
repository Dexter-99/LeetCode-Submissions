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
  int widthOfBinaryTree(TreeNode *root)
  {

    if (root == NULL)
      return 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    long long _max = 0;
    while (!q.empty())
    {
      long long len = q.size();
      long long first = -1, second = -1;
      for (int i = 0; i < len; i++)
      {
        TreeNode *curr = q.front().first;
        long long val = q.front().second;
        q.pop();
        if (i == 0)
        {
          first = val;
        }
        if (i == len - 1)
        {
          second = val;
        }
        if (curr->left)
          q.push({curr->left, 2 * val + 1});
        if (curr->right)
          q.push({curr->right, 2 * val + 2});
      }
      if (first != -1 && second != -1)
      {
        _max = max(_max, second - first + 1);
      }
      // cout<<endl;
    }
    return _max;
  }
};