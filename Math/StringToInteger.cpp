class Solution
{
public:
  string trim(const string &str)
  {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
      return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
  }
  int myAtoi(string s)
  {
    long long res = 0;
    bool negative = false;
    bool num = false;
    s = trim(s);
    int n = s.length();
    if (s[0] == '-')
    {
      negative = true;
    }
    if (s[0] == '+')
    {
      negative = false;
    }
    if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0] == '.')
      return 0;
    if (s[0] >= '0' && s[0] <= '9')
    {
      res = res * 10 + (s[0] - 48);
      num = true;
    }

    for (int i = 1; i < n; i++)
    {
      if (s[i] >= '0' && s[i] <= '9')
      {
        res = res * 10 + (s[i] - 48);

        if (negative && (res * -1) < INT32_MIN)
          return INT32_MIN;
        if (!negative && res > INT32_MAX)
          return INT32_MAX;
        num = true;
      }
      else
      {
        break;
      }
    }
    if (negative)
    {
      res *= -1;
    }
    if (!num)
      return 0;

    return res;
  }
};