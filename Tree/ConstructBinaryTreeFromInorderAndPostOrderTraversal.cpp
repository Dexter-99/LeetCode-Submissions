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
  TreeNode *solve(vector<int> &ino, vector<int> &pos, int inS, int inE, int posS, int posE, unordered_map<int, int> &mp)
  {
    if (inS > inE || posS > posE)
      return NULL;
    // cout<<preS<<" "<<preE<<endl;
    TreeNode *root = new TreeNode(pos[posE]);
    int mid = mp[root->val];
    int rem = mid - inS;
    root->left = solve(ino, pos, inS, mid - 1, posS, posS + rem - 1, mp);
    root->right = solve(ino, pos, mid + 1, inE, posS + rem, posE - 1, mp);
    return root;
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
      mp[inorder[i]] = i;
    }
    int n = inorder.size();
    return solve(inorder, postorder, 0, n - 1, 0, n - 1, mp);
  }
};