class Solution
{
public:
  int solve(int i, int j, int m, int n, vector<vector<int>> &grid)
  {
    if (i >= m || i >= n)
      return 0;
    if (i == m - 1 && j == n - 1)
      return 1;

    if (grid[i][j] != -1)
      return grid[i][j];

    return grid[i][j] = (solve(i + 1, j, m, n, grid) + solve(i, j + 1, m, n, grid));
  }
  int uniquePaths(int m, int n)
  {
    vector<vector<int>> grid(m, vector<int>(n, -1));
    return solve(0, 0, m, n, grid);
  }
};