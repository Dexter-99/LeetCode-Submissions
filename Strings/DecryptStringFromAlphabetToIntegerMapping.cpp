class Solution
{
public:
  string freqAlphabets(string s)
  {
    string res = "";
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '#')
      {
        res += (char)(s[i - 1] - 48 + (s[i - 2] - 48) * 10 + 96);
      }
      else
      {
        if (i + 1 < n && s[i + 1] == '#')
        {
          continue;
        }
        else if (i + 2 < n && s[i + 2] == '#')
        {
          continue;
        }
        else
        {
          res += (char)(s[i] - 48 + 96);
        }
      }
    }
    return res;
  }
};