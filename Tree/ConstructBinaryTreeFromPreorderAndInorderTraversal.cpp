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
  TreeNode *solve(vector<int> &ino, vector<int> &pre, int inS, int inE, int preS, int preE, unordered_map<int, int> &mp)
  {
    if (inS > inE || preS > preE)
      return NULL;

    TreeNode *root = new TreeNode(pre[preS]);
    int mid = mp[root->val];
    int rem = mid - inS;
    root->left = solve(ino, pre, inS, mid - 1, preS + 1, preS + rem, mp);
    root->right = solve(ino, pre, mid + 1, inE, preS + rem + 1, preE, mp);
    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {

    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
      mp[inorder[i]] = i;
    }
    int n = inorder.size();
    return solve(inorder, preorder, 0, n - 1, 0, n - 1, mp);
  }
};