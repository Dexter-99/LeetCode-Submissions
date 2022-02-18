class Solution
{
public:
  int beautySum(string s)
  {
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
      vector<int> a(26, 0);
      for (int j = i; j < s.length(); j++)
      {
        a[s[j] - 'a']++;
        int _max = 0, _min = s.length();
        for (int k = 0; k < 26; k++)
        {
          if (a[k] > 0)
          {
            _max = max(_max, a[k]);
            _min = min(_min, a[k]);
          }
        }
        sum += _max - _min;
      }
    }
    return sum;
  }
};