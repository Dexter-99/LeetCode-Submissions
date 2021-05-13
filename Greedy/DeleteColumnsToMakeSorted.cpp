class Solution
{
public:
  int minDeletionSize(vector<string> &strs)
  {
    int res = 0;
    int m = strs.size();
    int n = strs[0].length();
    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j < m; j++)
      {
        if (strs[j][i] < strs[j - 1][i])
        {
          res++;
          break;
        }
      }
    }
    return res;
  }
};