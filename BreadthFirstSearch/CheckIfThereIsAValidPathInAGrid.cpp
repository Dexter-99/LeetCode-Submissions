class Solution
{
public:
  bool bfs(vector<vector<int>> &grid, int i, int j)
  {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
      pair<int, int> p = q.front();
      q.pop();
      int currI = p.first, currJ = p.second;
      int val = grid[currI][currJ];
      grid[currI][currJ] = 0;
      int x[4] = {-1, 1, 0, 0};
      int y[4] = {0, 0, -1, 1};
      for (int i = 0; i < 4; i++)
      {
        int currX = currI + x[i];
        int currY = currJ + y[i];
        if (currX < 0 || currX == m || currY < 0 || currY == n || grid[currX][currY] == 0)
          continue;
        int adj = grid[currX][currY];
        if (val == 1)
        {
          if (y[i] == 1 && (adj == 3 || adj == 5 || adj == 1))
            q.push({currX, currY});
          if (y[i] == -1 && (adj == 4 || adj == 6 || adj == 1))
            q.push({currX, currY});
        }
        else if (val == 2)
        {

          if (x[i] == 1 && (adj == 5 || adj == 6 || adj == 2))
            q.push({currX, currY});
          if (x[i] == -1 && (adj == 3 || adj == 4 || adj == 2))
            q.push({currX, currY});
        }
        else if (val == 3)
        {
          if (y[i] == -1 && (adj == 4 || adj == 6 || adj == 1))
            q.push({currX, currY});
          if (x[i] == 1 && (adj == 5 || adj == 6 || adj == 2))
            q.push({currX, currY});
        }
        else if (val == 4)
        {
          if (y[i] == 1 && (adj == 5 || adj == 3 || adj == 1))
            q.push({currX, currY});
          if (x[i] == 1 && (adj == 5 || adj == 6 || adj == 2))
            q.push({currX, currY});
        }
        else if (val == 5)
        {
          if (x[i] == -1 && (adj == 3 || adj == 4 || adj == 2))
            q.push({currX, currY});
          if (y[i] == -1 && (adj == 4 || adj == 6 || adj == 1))
            q.push({currX, currY});
        }
        else if (val == 6)
        {
          if (y[i] == 1 && (adj == 3 || adj == 5 || adj == 1))
            q.push({currX, currY});
          if (x[i] == -1 && (adj == 4 || adj == 3 || adj == 2))
            q.push({currX, currY});
        }
      }
    }
    return (grid[m - 1][n - 1] == 0);
  }
  bool hasValidPath(vector<vector<int>> &grid)
  {
    return bfs(grid, 0, 0);
  }
};