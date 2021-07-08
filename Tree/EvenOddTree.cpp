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
  bool isEvenOddTree(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);
    int count = 1;
    while (!q.empty())
    {
      int size = q.size();
      ;
      TreeNode *curr, *prev = NULL;
      for (int i = 0; i < size; i++)
      {
        curr = q.front();
        q.pop();
        if (count & 1)
        {
          if (curr->val % 2 == 0)
            return false;
          if (prev != NULL)
          {
            if (curr->val <= prev->val)
              return false;
          }
        }
        else
        {
          if (curr->val % 2 != 0)
            return false;
          if (prev != NULL)
          {
            if (curr->val >= prev->val)
              return false;
          }
        }

        if (curr->left)
        {
          q.push(curr->left);
        }
        if (curr->right)
        {
          q.push(curr->right);
        }
        prev = curr;
      }
      count++;
    }
    return true;
  }
};