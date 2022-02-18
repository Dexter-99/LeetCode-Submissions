
int Solution::solve(int A)
{

  // We need to check three cases for finding the digital root

  // Case 1:
  if (A == 0)
    return 0;

  // Case 2:
  else if (A % 9 == 0)
    return 9;

  // Case 3:
  return A % 9;
}
