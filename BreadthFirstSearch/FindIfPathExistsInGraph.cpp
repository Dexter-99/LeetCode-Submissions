class Solution
{
public:
  bool dfs(vector<int> adj[], int u, int target, vector<bool> &visited)
  {
    if (u == target)
      return true;
    visited[u] = true;
    for (auto v : adj[u])
    {
      if (visited[v] == false)
      {
        if (dfs(adj, v, target, visited))
          return true;
      }
    }
    return false;
  }
  bool validPath(int n, vector<vector<int>> &edges, int start, int end)
  {
    vector<int> adj[n];
    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<bool> visited(n, false);

    return dfs(adj, start, end, visited);
  }
};