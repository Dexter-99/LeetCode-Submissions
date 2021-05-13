#include<iostream>
#include<queue>
#include<vector>
using namespace std;
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
  vector<int> largestValues(TreeNode *root)
  {
    queue<TreeNode *> q;
    vector<int> v;
    if (root == NULL)
      return v;
    q.push(root);
    while (!q.empty())
    {
      int count = q.size();
      int _max = INT32_MIN;
      for (int i = 0; i < count; i++)
      {
        TreeNode *curr = q.front();
        q.pop();
        _max = max(_max, curr->val);
        if (curr->left != NULL)
          q.push(curr->left);
        if (curr->right != NULL)
          q.push(curr->right);
      }
      v.push_back(_max);
    }
    return v;
  }
};