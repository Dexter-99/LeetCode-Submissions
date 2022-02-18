/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  TreeNode *recoverFromPreorder(string s)
  {
    int n = s.length();
    stack<TreeNode *> st;
    int i = 0;
    while (i < n)
    {
      int l = 0;
      while (s[i] == '-')
      {
        l++;
        i++;
      }
      int j = i;
      while (s[i] >= '0' && s[i] <= '9')
      {
        i++;
      }
      int val = stoi(s.substr(j, i - j + 1));
      TreeNode *curr = new TreeNode(val);
      if (st.empty())
      {
        st.push(curr);
        continue;
      }
      while (st.size() > l)
        st.pop();

      TreeNode *node = st.top();
      if (node->left)
        node->right = curr;
      else
        node->left = curr;
      st.push(curr);
    }
    while (st.size() > 1)
      st.pop();
    return st.top();
  }
};