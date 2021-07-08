class Solution
{
public:
  int solve(vector<vector<int>> &grid, int i, int j)
  {
    int m = grid.size();
    int n = grid[0].size();
    int total = 0;
    if (i < 1 || grid[i - 1][j] == 0)
      total++;
    if (i == m - 1 || grid[i + 1][j] == 0)
      total++;
    if (j < 1 || grid[i][j - 1] == 0)
      total++;
    if (j == n - 1 || grid[i][j + 1] == 0)
      total++;
    return total;
  }
  int islandPerimeter(vector<vector<int>> &grid)
  {
    int total = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 1)
          total += solve(grid, i, j);
      }
    }
    return total;
  }
};