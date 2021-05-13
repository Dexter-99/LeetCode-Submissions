class Solution
{
public:
  bool canThreePartsEqualSum(vector<int> &A)
  {
    int n = A.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += A[i];
    }
    if (sum % 3 != 0)
      return false;
    sum = sum / 3;
    int res = 0;
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
      temp += A[i];
      if (temp == sum)
      {
        temp = 0;
        res++;
      }
    }
    return res >= 3;
  }
};