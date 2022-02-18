void solve(Node *root, long long curr, long long &ans)
{
  if (root == NULL)
    return;

  curr = curr * 10 + root->data;
  if (root->left == NULL && root->right == NULL)
  {
    ans += curr;
    return;
  }
  solve(root->left, curr, ans);
  solve(root->right, curr, ans);
}
long long treePathsSum(Node *root)
{
  long long ans = 0;
  solve(root, 0, ans);
  return ans;
  //Your code here
}