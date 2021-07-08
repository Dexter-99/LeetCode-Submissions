class Solution
{
public:
  int maxChunksToSorted(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> right(n + 1, 0);
    right[n] = INT32_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
      right[i] = min(right[i + 1], arr[i]);
    }
    vector<int> left(n, 0);
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
      left[i] = max(left[i - 1], arr[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      if (left[i] <= right[i + 1])
        count++;
    }
    return count;
  }
};