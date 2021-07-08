class Solution
{
public:
  string maxValue(string n, int x)
  {
    int len = n.length();
    string res = "";
    if (n[0] == '-')
    {
      res += "-";
      int i;
      for (i = 1; i < len; i++)
      {
        if (x < n[i] - '0')
        {
          res += (char)(x + '0') + n.substr(i);
          break;
        }
        res += n[i];
      }
      if (i == len)
      {
        res += (char)(x + '0');
      }
    }
    else
    {
      int i;
      for (i = 0; i < len; i++)
      {
        if (x > n[i] - '0')
        {
          res += (char)(x + '0') + n.substr(i);
          break;
        }
        res += n[i];
      }
      if (i == len)
      {
        res += (char)(x + '0');
      }
    }
    return res;
  }
};