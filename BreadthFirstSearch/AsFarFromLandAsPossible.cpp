class Solution
{
public:
  int maxDistance(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> dist(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j])
        {
          q.push({i, j});
          dist[i][j] = 0;
        }
      }
    }
    if (q.empty())
      return -1;
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
          int currI = i + x[k];
          int currJ = j + y[k];
          if (currI < 0 || currI == m || currJ < 0 || currJ == n || dist[currI][currJ] != -1)
          {
            continue;
          }
          q.push({currI, currJ});
          dist[currI][currJ] = dist[i][j] + 1;
        }
      }
    }
    int res = -1;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 0)
        {
          res = max(res, dist[i][j]);
        }
      }
    }
    return res;
  }
};