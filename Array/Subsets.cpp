class Solution
{
public:
  vector<vector<int>> list;
  void solve(vector<int> &nums, vector<int> &res, int i)
  {
    if (i == nums.size())
    {
      list.push_back(res);
      return;
    }
    solve(nums, res, i + 1);
    res.push_back(nums[i]);
    solve(nums, res, i + 1);
    res.pop_back();
    return;
  }
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<int> res;
    solve(nums, res, 0);
    return list;
  }
};