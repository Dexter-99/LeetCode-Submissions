class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    int n = coins.size();
    int sum = amount;
    long long dp[sum + 1];
    dp[0] = 0;
    for (int i = 1; i <= sum; i++)
    {
      dp[i] = INT32_MAX;
      for (int j = 0; j < n; j++)
      {
        if (i >= coins[j])
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
    if (dp[sum] >= INT32_MAX)
      return -1;
    return dp[sum];
  }
};