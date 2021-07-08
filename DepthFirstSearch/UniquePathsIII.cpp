class Solution
{
public:
  int dfs(vector<vector<int>> &grid, int i, int j, int m, int n, int z, int totalZ)
  {

    if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == -1)
      return 0;
    if (grid[i][j] == 2)
    {
      if (z == totalZ)
        return 1;
      else
        return 0;
    }
    grid[i][j] = -1;
    int paths = (dfs(grid, i + 1, j, m, n, z + 1, totalZ) +
                 dfs(grid, i - 1, j, m, n, z + 1, totalZ) +
                 dfs(grid, i, j + 1, m, n, z + 1, totalZ) +
                 dfs(grid, i, j - 1, m, n, z + 1, totalZ));
    grid[i][j] = 0;
    return paths;
  }
  int uniquePathsIII(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    int z = 0;
    int x = 0, y = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] != -1)
          z++;
        if (grid[i][j] == 1)
        {
          x = i;
          y = j;
        }
      }
    }

    return dfs(grid, x, y, m, n, 1, z);
  }
};