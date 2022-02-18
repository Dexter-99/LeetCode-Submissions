class Solution
{
public:
  const int MOD = 1e9 + 7;
  long long solve(Node *root1, Node *root2)
  {
    if (root1 == NULL || root2 == NULL)
      return 0;
    long long val = ((root1->data) * (root2->data)) % MOD;
    return (val + (solve(root1->left, root2->right) + solve(root1->right, root2->left)) % MOD) % MOD;
  }
  long long imgMultiply(Node *root)
  {
    long long ans = (root->data * root->data) % MOD;
    return (ans + solve(root->left, root->right)) % MOD;
    // code here
  }
};