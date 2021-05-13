class Solution
{
public:
  int minOperations(int n)
  {
    if (n == 1)
      return 0;
    int arr[n];
    for (int i = 0; i < n; i++)
      arr[i] = 2 * i + 1;
    int mid = arr[n / 2];
    int mid1 = arr[(n / 2) - 1];
    int res = 0, res1 = 0;
    for (int i = 0; i < n; i++)
    {
      res = res + abs(arr[i] - mid);
      res1 = res1 + abs(arr[i] - mid1);
    }
    return min(res, res1) / 2;
  }
};