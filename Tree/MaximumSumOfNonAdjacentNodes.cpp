class Solution
{
public:
  //Function to return the maximum sum of non-adjacent nodes.
  unordered_map<Node *, int> dp;
  int solve(Node *root)
  {
    if (root == NULL)
      return 0;

    if (dp.find(root) != dp.end())
      return dp[root];

    int inc = root->data;

    if (root->left)
    {
      inc += solve(root->left->left);
      inc += solve(root->left->right);
    }
    if (root->right)
    {
      inc += solve(root->right->left);
      inc += solve(root->right->right);
    }

    int exc = solve(root->left) + solve(root->right);
    return dp[root] = max(inc, exc);
  }
  int getMaxSum(Node *root)
  {
    // Add your code here
    return solve(root);
  }
};
