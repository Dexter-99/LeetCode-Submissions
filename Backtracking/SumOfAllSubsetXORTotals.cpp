class Solution
{
public:
  int total = 0;
  void subset(vector<int> &nums, int n, int res)
  {
    if (n < 0)
    {
      total += res;
      return;
    }
    res ^= nums[n];
    subset(nums, n - 1, res);
    res ^= nums[n];
    subset(nums, n - 1, res);
  }
  int subsetXORSum(vector<int> &nums)
  {
    subset(nums, nums.size() - 1, 0);
    return total;
  }
};