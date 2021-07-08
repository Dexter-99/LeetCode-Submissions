class Solution
{
public:
  void addEdge(vector<int> adj[], int u, int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bool dfs(vector<int> adj[], int u, vector<int> &color)
  {
    if (color[u] == -1)
      color[u] = 0;
    for (auto v : adj[u])
    {
      if (color[v] == -1)
      {
        color[v] = color[u] ^ 1;
        if (dfs(adj, v, color) == false)
          return false;
      }
      else if (color[v] == color[u])
      {
        return false;
      }
    }
    return true;
  }
  bool possibleBipartition(int N, vector<vector<int>> &dislikes)
  {
    vector<int> adj[N + 1];
    vector<int> color(N + 1, -1);
    for (int i = 0; i < dislikes.size(); i++)
    {
      addEdge(adj, dislikes[i][0], dislikes[i][1]);
    }
    for (int i = 1; i <= N; i++)
    {
      if (color[i] == -1)
      {
        if (!dfs(adj, i, color))
          return false;
      }
    }
    return true;
  }
};