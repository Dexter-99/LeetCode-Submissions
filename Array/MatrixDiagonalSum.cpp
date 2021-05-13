class Solution
{
public:
  int diagonalSum(vector<vector<int>> &mat)
  {
    int sum = 0;
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j)
        {
          if (i == (n - 1 - j))
            sum += mat[i][j];
          else
            sum += mat[i][j] + mat[i][n - j - 1];
        }
      }
    }
    return sum;
  }
};