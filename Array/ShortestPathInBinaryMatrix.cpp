class Solution
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    if (grid[0][0] == 0)
    {
      q.push({{0, 0}, 1});
      grid[0][0] = -1;
    }
    while (!q.empty())
    {
      pair<pair<int, int>, int> p = q.front();
      q.pop();
      int i = p.first.first;
      int j = p.first.second;
      int d = p.second;
      if (i == m - 1 && j == n - 1)
      {
        return d;
      }
      int x[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
      int y[8] = {0, 0, -1, 1, -1, 1, -1, 1};
      for (int k = 0; k < 8; k++)
      {
        int currI = i + x[k];
        int currJ = j + y[k];
        if (currI < 0 || currI == m || currJ < 0 || currJ == n || grid[currI][currJ] == -1)
        {
          continue;
        }
        if (grid[currI][currJ] == 0)
        {
          q.push({{currI, currJ}, d + 1});
          grid[currI][currJ] = -1;
        }
      }
    }
    return -1;
  }
};