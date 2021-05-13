class Solution
{
public:
  bool isCousins(TreeNode *root, int x, int y)
  {
    if (root == NULL)
      return false;
    queue<pair<TreeNode *, TreeNode *>> q;
    q.push({root, NULL});
    while (!q.empty())
    {
      bool flag1 = false, flag2 = false;
      int len = q.size();
      TreeNode *parent = NULL;
      for (int i = 0; i < len; i++)
      {
        pair<TreeNode *, TreeNode *> curr = q.front();
        q.pop();

        if (curr.first->val == x)
        {
          if (parent == NULL)
          {
            parent = curr.second;
            flag1 = true;
          }
          else
          {
            if (curr.second != parent)
              flag1 = true;
          }
        }
        if (curr.first->val == y)
        {
          if (parent == NULL)
          {
            parent = curr.second;
            flag2 = true;
          }
          else
          {
            if (curr.second != parent)
              flag2 = true;
          }
        }
        if (curr.first->left != NULL)
          q.push({curr.first->left, curr.first});
        if (curr.first->right != NULL)
          q.push({curr.first->right, curr.first});
      }
      if (flag1 && flag2)
        return true;
    }
    return false;
  }
};