class Solution
{
public:
  int findBottomLeftValue(TreeNode *root)
  {
    queue<TreeNode *> q;
    int val = -1;
    q.push(root);
    while (!q.empty())
    {
      int len = q.size();
      for (int i = 0; i < len; i++)
      {
        TreeNode *curr = q.front();
        q.pop();
        if (i == 0)
          val = curr->val;
        if (curr->left != NULL)
          q.push(curr->left);
        if (curr->right != NULL)
          q.push(curr->right);
      }
    }
    return val;
  }
};