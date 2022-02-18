class Solution
{
public:
  int countNumbersWithUniqueDigits(int n)
  {
    if (n == 0)
      return 1;

    int ans = 10, mul = 9;
    for (int i = 2; i <= n; i++)
    {
      mul *= (9 - i + 2);
      ans += mul;
    }
    return ans;
  }
};