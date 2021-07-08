class Solution
{
public:
  int maxLengthBetweenEqualCharacters(string s)
  {
    vector<int> a(26, -1);
    int _max = -1;
    for (int i = 0; i < s.length(); i++)
    {
      if (a[s[i] - 'a'] == -1)
      {
        a[s[i] - 'a'] = i;
      }
      else
      {
        _max = max(i - a[s[i] - 'a'] - 1, _max);
      }
    }
    return _max;
  }
};