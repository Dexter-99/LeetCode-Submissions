class Solution
{
public:
  bool checkPerfectNumber(int num)
  {
    if (num < 2)
      return false;
    int sum = 1;
    for (int i = 2; i <= sqrt(num); i++)
    {
      if (num % i == 0)
      {
        if (i == num / i)
        {
          sum += i;
        }
        else
        {
          sum += i + num / i;
        }
      }
    }
    return sum == num;
  }
};