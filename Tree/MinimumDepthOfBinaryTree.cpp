// DFS WAY
class Solution
{
public:
  int minDepth(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    if (root->left == NULL && root->right == NULL)
      return 1;

    else
    {
      if (root->left == NULL)
        return minDepth(root->right) + 1;
      else if (root->right == NULL)
        return minDepth(root->left) + 1;
      else
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
  }
};

// BFS WAY

class Solution
{
public:
  int minDepth(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    queue<TreeNode *> q;
    int c = 1;
    q.push(root);
    while (!q.empty())
    {
      int len = q.size();
      for (int i = 0; i < len; i++)
      {
        TreeNode *curr = q.front();
        q.pop();
        if (curr->right == NULL && curr->left == NULL)
          return c;

        if (curr->left != NULL)
          q.push(curr->left);
        if (curr->right != NULL)
          q.push(curr->right);
      }
      c++;
    }
    return 0;
  }
};