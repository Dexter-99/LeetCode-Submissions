class Solution
{
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
  {
    vector<vector<int>> res(r, vector<int>(c, 0));

    int m = nums.size();
    int n = nums[0].size();
    if (m * n != r * c)
      return nums;
    int x = 0, y = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (y == c)
        {
          x++;
          y = 0;
        }
        res[x][y++] = nums[i][j];
      }
    }
    return res;
  }
};