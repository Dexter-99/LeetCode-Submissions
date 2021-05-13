class Solution
{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> res;
    if (root == NULL)
      return res;
    vector<int> list;
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;
    st1.push(root);
    while (!st1.empty() || !st2.empty())
    {
      while (!st1.empty())
      {
        TreeNode *curr = st1.top();
        st1.pop();
        list.push_back(curr->val);
        if (curr->left != NULL)
          st2.push(curr->left);
        if (curr->right != NULL)
          st2.push(curr->right);
      }
      if (!list.empty())
        res.push_back(list);
      list.clear();
      while (!st2.empty())
      {
        TreeNode *curr = st2.top();
        st2.pop();
        list.push_back(curr->val);
        if (curr->right != NULL)
          st1.push(curr->right);
        if (curr->left != NULL)
          st1.push(curr->left);
      }
      if (!list.empty())
        res.push_back(list);
      list.clear();
    }
    return res;
  }
};