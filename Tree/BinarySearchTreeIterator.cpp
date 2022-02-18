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
class BSTIterator
{
public:
  stack<TreeNode *> st;
  TreeNode *curr;

  BSTIterator(TreeNode *root)
  {
    curr = root;
    while (curr)
    {
      st.push(curr);
      curr = curr->left;
    }
  }

  /** @return the next smallest number */
  int next()
  {
    int ans = -1;
    while (curr != NULL)
    {
      st.push(curr);
      curr = curr->left;
    }
    if (curr == NULL)
    {

      curr = st.top();
      st.pop();
      ans = curr->val;
      curr = curr->right;
    }
    return ans;
  }

  /** @return whether we have a next smallest number */
  bool hasNext()
  {
    return curr != NULL || !st.empty();
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */