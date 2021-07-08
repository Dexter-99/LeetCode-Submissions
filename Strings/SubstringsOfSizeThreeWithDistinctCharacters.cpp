class Solution
{
public:
  int countGoodSubstrings(string s)
  {
    if (s.length() < 3)
      return 0;
    vector<int> a(26, 0);
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
      a[s[i] - 'a']++;
      int j;
    }
    int j;
    for (j = 0; j < 26; j++)
    {
      if (a[j] > 1)
      {
        break;
      }
    }
    if (j == 26)
      count++;
    for (int i = 3; i < s.length(); i++)
    {
      a[s[i] - 'a']++;
      a[s[i - 3] - 'a']--;
      int j;
      for (j = 0; j < 26; j++)
      {
        if (a[j] > 1)
        {
          break;
        }
      }
      if (j == 26)
        count++;
    }
    return count;
  }
};