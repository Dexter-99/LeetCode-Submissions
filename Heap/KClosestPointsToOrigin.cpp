class Solution
{
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    priority_queue<pair<double, pair<int, int>>> pq;
    for (int i = 0; i < points.size(); i++)
    {
      int x = points[i][0];
      int y = points[i][1];
      double res = sqrt(pow(x, 2) + pow(y, 2));

      if (pq.size() < k)
      {
        pq.push({res, {x, y}});
      }
      else
      {
        if (res < pq.top().first)
        {
          pq.pop();
          pq.push({res, {x, y}});
        }
      }
    }
    vector<vector<int>> ans;
    while (!pq.empty())
    {

      ans.push_back({pq.top().second.first, pq.top().second.second});
      pq.pop();
    }
    return ans;
  }
};