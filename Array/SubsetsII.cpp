class Solution
{
public:
  vector<vector<int>> list;
  void solve(vector<int> &nums, vector<int> &res, int i)
  {
    list.push_back(res);
    if (i == nums.size())
    {
      return;
    }
    for (int j = i; j < nums.size(); j++)
    {
      if (j > i && nums[j] == nums[j - 1])
        continue;
      res.push_back(nums[j]);
      solve(nums, res, j + 1);
      res.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    vector<int> res;
    sort(nums.begin(), nums.end());
    solve(nums, res, 0);
    return list;
  }
};
