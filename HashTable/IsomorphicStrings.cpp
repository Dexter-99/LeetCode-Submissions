class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    map<char, char> mp;
    unordered_set<int> h;
    for (int i = 0; i < s.length(); i++)
    {
      if (mp.find(s[i]) == mp.end())
      {
        if (h.find(t[i]) == h.end())
        {
          h.insert(t[i]);
          mp[s[i]] = t[i];
        }
        else
          return false;
      }
      else
      {
        if (mp[s[i]] != t[i])
          return false;
      }
    }
    return true;
  }
};