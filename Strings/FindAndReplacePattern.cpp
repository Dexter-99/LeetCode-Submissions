class Solution
{
public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern)
  {
    vector<string> list;
    int n = words.size();
    unordered_map<char, char> mp;
    unordered_set<char> h;
    for (int j = 0; j < n; j++)
    {
      string s = words[j];
      bool flag = true;
      for (int i = 0; i < s.length(); i++)
      {
        if (mp.find(s[i]) == mp.end())
        {
          if (h.find(pattern[i]) == h.end())
          {
            h.insert(pattern[i]);
            mp[s[i]] = pattern[i];
          }
          else
          {
            flag = false;
            break;
          }
        }
        else
        {
          if (mp[s[i]] != pattern[i])
          {
            flag = false;
            break;
          }
        }
      }
      if (flag)
        list.push_back(s);
      mp.clear();
      h.clear();
    }
    return list;
  }
};