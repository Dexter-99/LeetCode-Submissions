class Solution
{
public:
  int climbStairs(int n)
  {
    if (n <= 2)
      return n;
    int one_step = 2, two_step = 1, curr_step = 0;
    for (int i = n - 3; i >= 0; i--)
    {
      curr_step = one_step + two_step;
      two_step = one_step;
      one_step = curr_step;
    }
    return curr_step;
  }
};