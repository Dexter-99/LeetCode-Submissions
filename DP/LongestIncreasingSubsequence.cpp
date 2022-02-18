// Memoization
class Solution
{
public:
  int dp[2503][2503];
  int solve(vector<int> &nums, int n, int curr)
  {
    if (n == 0)
      return 0;

    if (dp[curr][n] != -1)
      return dp[curr][n];

    int res = 0;

    if (curr == nums.size() + 1 || nums[n - 1] < nums[curr - 1])
    {
      res = 1 + solve(nums, n - 1, n);
    }
    res = max(res, solve(nums, n - 1, curr));
    return dp[curr][n] = res;
  }
  int lengthOfLIS(vector<int> &nums)
  {
    memset(dp, -1, sizeof(dp));
    return solve(nums, nums.size(), nums.size() + 1);
  }
};
// Tabulation
class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    int dp[n];
    dp[0] = 1;
    int res = dp[0];
    for (int i = 1; i < n; i++)
    {
      int _max = 0;
      for (int j = 0; j < i; j++)
      {
        if (nums[j] < nums[i])
        {
          _max = max(_max, dp[j]);
        }
      }
      dp[i] = _max + 1;
      res = max(res, dp[i]);
    }
    return res;
  }
};
// BinarySearchR
class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    if (nums.size() == 0)
      return 0;
    int tail[n];
    tail[0] = nums[0];
    int len = 1;
    for (int i = 1; i < n; i++)
    {
      if (nums[i] > tail[len - 1])
      {
        tail[len++] = nums[i];
      }
      else
      {
        auto it = lower_bound(tail, tail + len, nums[i]);
        int idx = it - tail;
        tail[idx] = nums[i];
      }
    }
    return len;
  }
};