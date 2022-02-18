class Solution
{
public:
  string multiply(string num1, string num2)
  {
    if (num1 == "0" || num2 == "0")
      return "0";
    int len1 = num1.length();
    int len2 = num2.length();

    vector<int> res(len1 + len2, 0);
    int i = len2 - 1;
    int step = 0;

    while (i >= 0)
    {
      int ival = num2[i] - '0';

      int j = len1 - 1, k = res.size() - 1 - step, carry = 0;
      while (j >= 0 || carry != 0)
      {
        int jval = (j >= 0) ? (num1[j] - '0') : 0;
        j--;

        int prod = ival * jval + carry + res[k];

        res[k] = prod % 10;
        carry = prod / 10;
        k--;
      }
      step++;
      i--;
    }

    string ans = "";
    bool flag = false;
    for (int i = 0; i < res.size(); i++)
    {
      if (res[i] == 0 && flag == false)
      {
      }
      else
      {
        flag = true;
        ans += (char)('0' + res[i]);
      }
    }
    return ans;
  }
};