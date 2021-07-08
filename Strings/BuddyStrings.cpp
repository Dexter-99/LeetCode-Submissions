class Solution
{
public:
  bool buddyStrings(string a, string b)
  {
    if (a.length() != b.length())
      return false;
    vector<int> list;
    vector<int> aux(26, 0);
    for (int i = 0; i < a.length(); i++)
    {
      if (a[i] != b[i])
        list.push_back(i);
      aux[a[i] - 'a']++;
    }
    if (a == b)
    {
      int count = 0;
      for (int i = 0; i < 26; i++)
      {
        if (aux[i] > 1)
          return true;
      }
      return false;
    }
    if (list.size() != 2)
      return false;
    swap(a[list[0]], a[list[1]]);
    return a == b;
  }
};