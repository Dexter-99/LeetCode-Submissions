class Solution
{
public:
  int getMaximumGenerated(int n)
  {
    if (n == 0)
      return 0;
    int a[n + 1];
    a[0] = 0;
    a[1] = 1;
    int _max = max(a[0], a[1]);
    for (int i = 2; i <= n; i++)
    {
      if (i % 2 == 0)
        a[i] = a[i / 2];
      else
        a[i] = a[(i - 1) / 2] + a[(i + 1) / 2];
      _max = max(_max, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    return _max;
  }
};