class Solution
{
public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
  {
    vector<vector<int>> dist(R, vector<int>(C, -1));
    vector<vector<int>> ans;
    queue<pair<int, int>> q;
    q.push({r0, c0});
    dist[r0][c0] = 0;

    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        int i = q.front().first;
        int j = q.front().second;
        ans.push_back({i, j});
        q.pop();

        for (int k = 0; k < 4; k++)
        {
          int currI = i + x[k];
          int currJ = j + y[k];
          if (currI < 0 || currJ < 0 || currI == R || currJ == C || dist[currI][currJ] != -1)
            continue;

          dist[currI][currJ] = dist[i][j] + 1;
          q.push({currI, currJ});
        }
      }
    }

    return ans;
  }
};