class Solution
{
public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes)
  {
    map<string, vector<int>> mp;
    int n = groupSizes.size();
    unordered_map<int, int> h;
    for (int i = 0; i < n; i++)
    {
      if (mp[to_string(groupSizes[i]) + to_string(h[groupSizes[i]])].size() == groupSizes[i])
      {
        h[groupSizes[i]]++;
      }

      mp[to_string(groupSizes[i]) + to_string(h[groupSizes[i]])].push_back(i);
    }
    vector<vector<int>> res;
    for (auto x : mp)
    {
      res.push_back(x.second);
    }
    return res;
  }
};