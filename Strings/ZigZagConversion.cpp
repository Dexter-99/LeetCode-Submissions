class Solution
{
public:
  string convert(string s, int numRows)
  {
    if (numRows == 1)
      return s;
    int len = min(numRows, (int)s.length());
    vector<string> ans(len, "");

    bool up = true;
    int curr = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (curr == 0 || (curr == numRows - 1))
        up = !up;

      ans[curr] += s[i];
      curr += (up) ? -1 : 1;
    }
    string res = "";
    for (auto x : ans)
      res += x;

    return res;
  }
};