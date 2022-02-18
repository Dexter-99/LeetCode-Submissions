class Solution
{
public:
  int slidingPuzzle(vector<vector<int>> &board)
  {
    vector<vector<int>> ans = {{1, 2, 3}, {4, 5, 0}};

    queue<vector<vector<int>>> q;
    set<vector<vector<int>>> h;
    q.push(board);
    h.insert(board);
    int steps = 0;
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        vector<vector<int>> curr = q.front();
        q.pop();
        if (curr == ans)
        {
          return steps;
        }
        for (int i = 0; i < 2; i++)
        {
          for (int j = 0; j < 3; j++)
          {
            if (curr[i][j] == 0)
            {
              vector<vector<int>> res = curr;
              for (int k = 0; k < 4; k++)
              {
                int currI = i + x[k];
                int currJ = j + y[k];
                if (currI < 0 || currI == 2 || currJ < 0 || currJ == 3)
                  continue;
                swap(res[i][j], res[currI][currJ]);
                if (h.find(res) == h.end())
                {
                  q.push(res);
                  h.insert(res);
                }
                swap(res[i][j], res[currI][currJ]);
              }
            }
          }
        }
      }
      steps++;
    }
    return -1;
  }
};