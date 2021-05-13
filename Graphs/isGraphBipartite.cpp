#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// The Graph in this case may be disconnected also so we have to check bipartiteness of each component and take the and value
class Solution
{
public:
  bool bfs(vector<vector<int>> &adj, int s, int v, bool visited[])
  {
    int color[v];
    for (int i = 0; i < v; i++)
      color[i] = -1;
    queue<int> q;
    q.push(s);
    color[s] = 0;
    visited[s] = true;
    while (!q.empty())
    {
      int curr = q.front();
      q.pop();
      for (int i : adj[curr])
      {
        if (color[i] == -1)
        {
          color[i] = 1 ^ color[curr];
          q.push(i);
          visited[s] = true;
        }
        else if (color[i] == color[curr])
          return false;
      }
    }
    return true;
  }
  bool isBipartite(vector<vector<int>> &graph)
  {
    int v = graph.size();
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
      visited[i] = false;
    }
    bool ans = true;
    for (int i = 0; i < v; i++)
    {
      if (visited[i] == false)
      {
        ans &= bfs(graph, i, v, visited);
      }
    }
    return ans;
  }
};