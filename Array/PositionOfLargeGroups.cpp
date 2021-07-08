class Solution
{
public:
  vector<vector<int>> largeGroupPositions(string s)
  {
    vector<vector<int>> list;
    int last = 0, n = s.length();
    for (int i = 1; i < n; i++)
    {
      if (s[i] != s[i - 1])
      {

        if (i - last >= 3)
        {
          list.push_back({last, i - 1});
        }
        last = i;
      }
    }
    if (last != n - 1)
    {
      if (n - last >= 3)
        list.push_back({last, n - 1});
    }
    return list;
  }
};