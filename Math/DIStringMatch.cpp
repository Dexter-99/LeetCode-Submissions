class Solution
{
public:
  vector<int> diStringMatch(string s)
  {
    int n = s.length();
    int a = 0;
    int b = n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'I')
        v.push_back(a++);
      else if (s[i] == 'D')
        v.push_back(b--);
    }
    v.push_back(a);
    return v;
  }
};