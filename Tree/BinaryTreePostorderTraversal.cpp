class Solution
{
public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> list;
    if (root == NULL)
      return list;

    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (!st.empty() || curr != NULL)
    {
      if (curr != NULL)
      {
        st.push(curr);
        curr = curr->left;
      }
      else
      {
        TreeNode *temp = st.top()->right;
        if (temp == NULL)
        {
          temp = st.top();
          st.pop();
          list.push_back(temp->val);
          while (!st.empty() && st.top()->right == temp)
          {
            temp = st.top();
            st.pop();
            list.push_back(temp->val);
          }
        }
        else
        {
          curr = temp;
        }
      }
    }
    return list;
  }
};