class Solution
{
public:
  int countNodes(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    int lh = 0, rh = 0;
    TreeNode *curr = root;
    while (curr != NULL)
    {
      lh++;
      curr = curr->left;
    }
    curr = root;
    while (curr != NULL)
    {
      rh++;
      curr = curr->right;
    }
    if (lh == rh)
      return pow(2, rh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};