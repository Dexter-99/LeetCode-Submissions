class Solution
{
public:
  string convertToBase7(int num)
  {
    if (num == 0)
      return "0";
    bool flag = false;
    if (num < 0)
    {
      num = ~num + 1;
      flag = true;
    }
    string res = "";
    while (num > 0)
    {
      int dig = num % 7;
      res = to_string(dig) + res;
      num /= 7;
    }
    if (flag)
    {
      res = "-" + res;
    }

    return res;
  }
};