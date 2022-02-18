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
  void collect(TreeNode *root, vector<int> &list)
  {
    if (root == NULL)
      return;
    collect(root->left, list);
    list.push_back(root->val);
    collect(root->right, list);
  }
  TreeNode *solve(vector<int> &list, int lo, int hi)
  {
    if (lo > hi)
      return NULL;

    int mid = lo + (hi - lo) / 2;
    TreeNode *root = new TreeNode(list[mid]);
    root->left = solve(list, lo, mid - 1);
    root->right = solve(list, mid + 1, hi);
    return root;
  }
  TreeNode *balanceBST(TreeNode *root)
  {
    vector<int> list;
    collect(root, list);

    return solve(list, 0, list.size() - 1);
  }
};