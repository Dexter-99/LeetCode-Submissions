class Solution
{
public:
  vector<vector<int>> list;
  void solve(vector<int> &nums, int i)
  {
    if (i == nums.size() - 1)
    {
      list.push_back(nums);
      return;
    }

    for (int j = i; j < nums.size(); j++)
    {
      swap(nums[i], nums[j]);
      solve(nums, i + 1);
      swap(nums[i], nums[j]);
    }
  }
  vector<vector<int>> permute(vector<int> &nums)
  {
    solve(nums, 0);
    return list;
  }
};