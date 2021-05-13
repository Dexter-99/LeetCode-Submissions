class Solution
{
public:
  int balanced(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    int lh = balanced(root->left);
    if (lh == -1)
      return -1;
    int rh = balanced(root->right);
    if (rh == -1)
      return -1;
    if (abs(lh - rh) > 1)
      return -1;
    return max(lh, rh) + 1;
  }
  bool isBalanced(TreeNode *root)
  {
    if (balanced(root) == -1)
      return false;
    return true;
  }
};