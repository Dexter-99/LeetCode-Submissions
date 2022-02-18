class Solution
{
public:
  int solve(int n, vector<int> &dp)
  {
    if (n == 2)
      return 1;
    if (dp[n] != -1)
      return dp[n];
    int _max = 1 * (n - 1);
    for (int i = 2; i < n; i++)
    {
      _max = max(_max, i * max(n - i, solve(n - i, dp)));
    }
    return dp[n] = _max;
  }
  int integerBreak(int n)
  {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
  }
};