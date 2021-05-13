class Solution
{
public:
  bool isUnivalTree(TreeNode *root)
  {
    if (root == NULL)
      return true;
    if (root->left == NULL && root->right == NULL)
      return true;
    if (root->left == NULL)
      return ((root->right->val == root->val) && isUnivalTree(root->right));
    if (root->right == NULL)
      return ((root->left->val == root->val) && isUnivalTree(root->left));
    return (root->left->val == root->val && root->right->val == root->val && isUnivalTree(root->left) && isUnivalTree(root->right));
  }
};