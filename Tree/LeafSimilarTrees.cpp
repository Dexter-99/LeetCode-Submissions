class Solution
{
public:
  void dfs(TreeNode *root, vector<int> &v)
  {
    if (root == NULL)
      return;
    if (root->left == NULL && root->right == NULL)
      v.push_back(root->val);
    dfs(root->left, v);
    dfs(root->right, v);
  }
  bool leafSimilar(TreeNode *root1, TreeNode *root2)
  {
    vector<int> l1;
    vector<int> l2;

    dfs(root1, l1);
    dfs(root2, l2);

    return (l1 == l2);
  }
};