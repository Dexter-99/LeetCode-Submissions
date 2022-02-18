class Solution
{
public:
  int numberOfBoomerangs(vector<vector<int>> &points)
  {
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < points.size(); i++)
    {
      for (int j = 0; j < points.size(); j++)
      {

        if (i == j)
          continue;
        int diffX = points[j][0] - points[i][0];
        int diffY = points[j][1] - points[i][1];
        int dist = diffX * diffX + diffY * diffY;
        mp[dist]++;
      }
      for (auto x : mp)
        ans = (ans + (x.second * (x.second - 1)));

      mp.clear();
    }

    return ans;
  }
};