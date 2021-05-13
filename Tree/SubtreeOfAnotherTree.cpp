class Solution
{
public:
  bool isSame(TreeNode *root1, TreeNode *root2)
  {
    if (root1 == NULL && root2 == NULL)
      return true;
    if (root1 == NULL || root2 == NULL)
      return false;
    return (root1->val == root2->val && isSame(root1->left, root2->left) && isSame(root1->right, root2->right));
  }
  bool isSubtree(TreeNode *s, TreeNode *t)
  {
    if (s == NULL)
      return false;
    if (t == NULL)
      return false;
    if (isSame(s, t))
      return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};