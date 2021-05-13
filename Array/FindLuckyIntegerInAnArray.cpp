class Solution
{
public:
  int findLucky(vector<int> &arr)
  {
    unordered_map<int, int> mp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      mp[arr[i]]++;
    }
    int res = 0;
    for (auto x : mp)
    {
      if ((x.second == x.first) && x.second >= res)
      {
        res = x.first;
      }
    }
    return res == 0 ? -1 : res;
  }
};