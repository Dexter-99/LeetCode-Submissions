class Solution
{
public:
  vector<int> closestDivisors(int num)
  {
    int val = 1;
    for (int i = 1; i <= sqrt(num + 2); i++)
    {
      if ((num + 1) % i == 0 || (num + 2) % i == 0)
      {
        val = max(val, i);
      }
    }
    if ((num + 1) % val == 0)
    {
      return {val, (num + 1) / val};
    }
    return {val, (num + 2) / val};
  }
};