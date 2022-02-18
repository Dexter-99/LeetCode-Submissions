class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    bool flag = false;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 2)
        {
          q.push({i, j});
          grid[i][j] = -1;
        }
        else if (grid[i][j] == 1)
        {
          flag = true;
        }
      }
    }
    if (q.empty())
    {
      if (flag)
        return -1;
      return 0;
    }
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    int count = 0;
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        pair<int, int> p = q.front();
        q.pop();
        int u = p.first;
        int v = p.second;

        // cout<<u<<" "<<v<<endl;
        for (int k = 0; k < 4; k++)
        {
          int currI = u + x[k];
          int currJ = v + y[k];
          if (currI < 0 || currI == m || currJ < 0 || currJ == n || grid[currI][currJ] == -1)
            continue;

          if (grid[currI][currJ] == 1)
          {
            q.push({currI, currJ});
            grid[currI][currJ] = -1;
          }
        }
      }
      count++;
    }
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
          return -1;
      }
    }
    return count - 1;
  }
};