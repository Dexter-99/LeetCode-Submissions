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
  int findSecondMinimumValue(TreeNode *root)
  {
    long long first = INT64_MAX;
    long long second = INT64_MAX;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *curr = q.front();
      q.pop();
      // cout<<second<<" "<<first<<endl;
      if (curr->val < first)
      {

        second = first;
        first = curr->val;
      }
      else if (curr->val < second && curr->val != first)
      {
        second = curr->val;
      }
      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
    }
    return (second == INT64_MAX ? -1 : second);
  }
};