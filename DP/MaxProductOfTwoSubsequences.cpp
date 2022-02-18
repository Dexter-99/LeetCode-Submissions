class Solution
{
public:
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
  {
    int m = nums1.size();
    int n = nums2.size();
    long long dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        if (i == 0 || j == 0)
        {
          dp[i][j] = INT32_MIN;
        }
        else
        {
          dp[i][j] = nums1[i - 1] * nums2[j - 1];
          dp[i][j] = max(max((long long)dp[i - 1][j - 1] + (nums1[i - 1] * nums2[j - 1]), dp[i][j]), max(dp[i - 1][j], dp[i][j - 1]));
        }
      }
    }
    return dp[m][n];
  }
};