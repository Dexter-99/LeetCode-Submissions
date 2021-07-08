class Solution
{
public:
  void addEdge(vector<int> adj[], int u, int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int findCenter(vector<vector<int>> &edges)
  {
    int n = edges.size();

    vector<int> adj[n + 2];
    for (int i = 0; i < n; i++)
    {
      addEdge(adj, edges[i][0], edges[i][1]);
    }
    for (int i = 1; i <= n + 1; i++)
    {
      if (adj[i].size() == n)
        return i;
    }
    return -1;
  }
};