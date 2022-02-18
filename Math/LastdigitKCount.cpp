int Solution::solve(int A, int B, int C)
{

  int dig = A % 10;
  if (C < dig)
  {
    A += (10 - dig);
    A += C;
  }
  else
  {
    A += (C - dig);
  }

  int count = 0;
  if (A > B)
    return 0;

  count = 1 + (B - A) / 10;
  return count;
}
