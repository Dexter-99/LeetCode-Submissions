class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    vector<int> list;
    if (s.length() < p.length())
      return list;
    vector<int> a1(26, 0);
    vector<int> a2(26, 0);
    for (int i = 0; i < p.length(); i++)
      a1[p[i] - 'a']++;
    for (int i = 0; i < p.length(); i++)
    {
      a2[s[i] - 'a']++;
    }
    if (a1 == a2)
      list.push_back(0);
    for (int i = p.length(); i < s.length(); i++)
    {

      a2[s[i] - 'a']++;
      a2[s[i - p.length()] - 'a']--;
      if (a1 == a2)
        list.push_back(i - p.length() + 1);
    }
    return list;
  }
};