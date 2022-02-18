/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  void helper(TreeNode *root, TreeNode *par, unordered_map<TreeNode *, TreeNode *> &mp)
  {
    if (root == NULL)
      return;
    mp[root] = par;
    helper(root->left, root, mp);
    helper(root->right, root, mp);
  }
  vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
  {
    unordered_map<TreeNode *, TreeNode *> mp;
    helper(root, NULL, mp);

    vector<int> ans;
    unordered_set<TreeNode *> h;
    queue<TreeNode *> q;
    q.push(target);
    h.insert(target);
    int count = 0;
    while (!q.empty())
    {
      int size = q.size();
      bool flag = false;
      while (size--)
      {
        TreeNode *curr = q.front();
        q.pop();
        if (count == K)
        {
          ans.push_back(curr->val);
          flag = true;
        }
        if (curr->left && h.find(curr->left) == h.end())
        {
          q.push(curr->left);
          h.insert(curr->left);
        }
        if (curr->right && h.find(curr->right) == h.end())
        {
          q.push(curr->right);
          h.insert(curr->right);
        }
        if (mp[curr] != NULL && h.find(mp[curr]) == h.end())
        {
          q.push(mp[curr]);
          h.insert(mp[curr]);
        }
      }
      count++;
      if (flag)
      {
        break;
      }
    }
    return ans;
  }
};