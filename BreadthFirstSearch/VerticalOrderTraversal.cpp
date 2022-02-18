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
  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    unordered_map<int, vector<pair<int, int>>> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    mp[0].push_back({root->val, 0});
    int _min = 1001;
    int _max = 0;
    int level = 1;
    while (!q.empty())
    {

      int size = q.size();
      while (size--)
      {
        TreeNode *curr = q.front().first;
        int val = q.front().second;
        q.pop();
        _min = min(_min, val);
        _max = max(_max, val);
        if (curr->left)
        {
          mp[val - 1].push_back({curr->left->val, level});
          q.push({curr->left, val - 1});
        }
        if (curr->right)
        {
          mp[val + 1].push_back({curr->right->val, level});
          q.push({curr->right, val + 1});
        }
      }

      level++;
    }
    vector<vector<int>> list;
    for (int i = _min; i <= _max; i++)
    {
      if (mp.find(i) == mp.end())
        continue;
      vector<pair<int, int>> res = mp[i];
      sort(res.begin(), res.end(), [](pair<int, int> a, pair<int, int> b)
           {
             if (a.second == b.second)
             {
               return a.first <= b.first;
             }
             return a.second < b.second;
           });
      vector<int> order;
      for (auto x : res)
        order.push_back(x.first);
      list.push_back(order);
    }
    return list;
  }
};