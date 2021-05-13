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
  vector<int> inorderTraversal(TreeNode *root)
  {
    //Iterative approach Using Stack

    TreeNode *curr = root;
    stack<TreeNode *> st;
    vector<int> list;
    while (curr != NULL || !st.empty())
    {
      if (curr != NULL)
      {
        st.push(curr);
        curr = curr->left;
      }
      else
      {
        curr = st.top();
        list.push_back(curr->val);
        st.pop();
        curr = curr->right;
      }
    }
    return list;
  }
};