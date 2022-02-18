class Solution
{
public:
  int numSplits(string s)
  {
    unordered_set<char> h;
    int n = s.length();
    vector<int> pre(n, 0);
    vector<int> suf(n, 0);
    for (int i = 0; i < n; i++)
    {
      h.insert(s[i]);
      pre[i] = h.size();
    }
    h.clear();
    for (int i = n - 1; i >= 0; i--)
    {
      h.insert(s[i]);
      suf[i] = h.size();
    }
    int count = 0;
    for (int i = 1; i < n; i++)
    {
      if (pre[i - 1] == suf[i])
        count++;
    }
    return count;
  }
};