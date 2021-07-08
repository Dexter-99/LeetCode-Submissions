class Solution
{
public:
  vector<int> partitionLabels(string s)
  {
    vector<int> a(26, -1);
    for (int i = 0; i < s.length(); i++)
    {
      a[s[i] - 'a'] = i;
    }

    vector<int> list;
    int prev = -1;
    int _max = 0;
    for (int i = 0; i < s.length(); i++)
    {
      _max = max(_max, a[s[i] - 'a']);
      if (_max == i)
      {
        list.push_back(i - prev);
        prev = i;
      }
    }
    return list;
  }
};