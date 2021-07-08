class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    int sum = 0;
    sum = accumulate(nums.begin(), nums.end(), sum);
    cout << sum << endl;
    if (sum & 1)
      return false;
    sum >>= 1;
    int n = nums.size();
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= sum; j++)
      {
        if (i == 0)
        {
          dp[i][j] = false;
        }
        else if (j == 0)
        {
          dp[i][j] = true;
        }
        else if (nums[i - 1] <= j)
        {
          dp[i][j] = (dp[i - 1][j - nums[i - 1]] || dp[i - 1][j]);
        }
        else
        {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    // cout<<d
    return dp[n][sum];
  }
};