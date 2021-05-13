class Solution
{
public:
  int numSpecial(vector<vector<int>> &mat)
  {
    int m = mat.size();
    int n = mat[0].size();
    int r[m], c[n];
    for (int i = 0; i < m; i++)
      r[i] = 0;
    for (int i = 0; i < n; i++)
      c[i] = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (mat[i][j])
        {
          r[i]++;
          c[j]++;
        }
      }
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (mat[i][j] && r[i] == 1 && c[j] == 1)
          count++;
      }
    }
    return count;
  }
};1