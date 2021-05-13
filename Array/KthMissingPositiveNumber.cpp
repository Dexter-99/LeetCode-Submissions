class Solution
{
public:
  int findKthPositive(vector<int> &arr, int k)
  {
    int n = arr.size();
    int last = arr[n - 1];
    last += k + 1;
    int aux[last];
    for (int i = 0; i < last; i++)
    {
      aux[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
      aux[arr[i]]++;
    }
    for (int i = 1; i < last; i++)
    {

      if (aux[i] == 0)
      {
        k--;
      }
      if (k == 0)
        return i;
    }
    return -1;
  }
};