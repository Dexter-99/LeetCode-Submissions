class Solution
{
public:
  int maxNumberOfBalloons(string text)
  {
    map<char, int> mp;
    string s = "balloon";
    int len = text.length();
    for (int i = 0; i < len; i++)
    {
      if (s.find(text[i]) != string::npos)
        mp[text[i]]++;
    }
    int res = INT32_MAX;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == 'o' || s[i] == 'l')
        res = min(res, mp[s[i]] / 2);
      else
        res = min(res, mp[s[i]]);
    }
    return res;
  }
};