class Solution
{
public:
  int maxLevelSum(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);
    long long val = INT64_MIN;
    int level = -1;
    q.push(root);
    int c = 1;
    while (!q.empty())
    {
      int len = q.size();
      long long sum = 0;
      for (int i = 0; i < len; i++)
      {
        TreeNode *curr = q.front();
        q.pop();
        sum += curr->val;
        if (curr->left != NULL)
          q.push(curr->left);
        if (curr->right != NULL)
          q.push(curr->right);
      }
      if (sum > val)
      {
        val = max(val, sum);
        level = c;
      }
      c++;
    }
    return level;
  }
};