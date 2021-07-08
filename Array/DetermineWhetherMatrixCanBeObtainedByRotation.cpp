class Solution
{
public:
  bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
  {
    vector<bool> rot(4, true);
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (mat[i][j] != target[i][j])
          rot[0] = false;
        if (mat[i][j] != target[j][n - i - 1])
          rot[1] = false;
        if (mat[i][j] != target[n - i - 1][n - j - 1])
          rot[2] = false;
        if (mat[i][j] != target[n - j - 1][i])
          rot[3] = false;
      }
    }
    return rot[0] || rot[1] || rot[2] || rot[3];
  }
};