class Solution
{
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &M)
  {

    int r[8] = {1, 1, 0, 0, -1, -1, -1, 1};
    int c[8] = {1, 0, 1, -1, 0, -1, 1, -1};
    int m = M.size();
    int n = M[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int total = M[i][j];
        int count = 1;
        for (int k = 0; k < 8; k++)
        {
          if (i + r[k] >= 0 && i + r[k] < m && j + c[k] >= 0 && j + c[k] < n)
          {
            total += M[i + r[k]][j + c[k]];
            count++;
          }
        }
        total = floor(total / (double)count);
        res[i][j] = total;
      }
    }
    return res;
  }
};