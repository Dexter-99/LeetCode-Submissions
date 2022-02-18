class Solution
{
public:
  string solve(string s1, string s2)
  {
    int m = s1.length();
    int n = s2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        else
        {
          if (s1[i - 1] == s2[j - 1])
            dp[i][j] = 1 + dp[i - 1][j - 1];
          else
          {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
          }
        }
      }
    }
    int i = m, j = n;
    string str = "";
    while (i > 0 && j > 0)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        str = s1[i - 1] + str;
        i--;
        j--;
      }
      else
      {
        if (dp[i - 1][j] >= dp[i][j - 1])
        {
          str = s1[i - 1] + str;
          i--;
        }
        else
        {
          str = s2[j - 1] + str;
          j--;
        }
      }
    }
    while (i > 0)
    {
      str = s1[i - 1] + str;
      i--;
    }
    while (j > 0)
    {
      str = s2[j - 1] + str;
      j--;
    }
    return str;
  }
  string shortestCommonSupersequence(string str1, string str2)
  {
    return solve(str1, str2);
  }
};