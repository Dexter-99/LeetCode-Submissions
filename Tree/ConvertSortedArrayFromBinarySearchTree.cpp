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
  TreeNode *bs(int low, int high, vector<int> &nums)
  {
    if (low > high)
      return NULL;
    int mid = low + (high - low) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = bs(low, mid - 1, nums);
    root->right = bs(mid + 1, high, nums);
    return root;
  }
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    return bs(0, nums.size() - 1, nums);
  }
};