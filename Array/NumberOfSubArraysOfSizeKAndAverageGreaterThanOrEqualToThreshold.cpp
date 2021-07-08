class Solution
{
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold)
  {
    int currSum = 0, count = 0;
    int n = arr.size();
    for (int i = 0; i < k; i++)
    {
      currSum += arr[i];
    }
    int avg = currSum / (double)k;
    if (avg >= threshold)
    {
      count++;
    }
    for (int i = k; i < n; i++)
    {
      currSum += arr[i] - arr[i - k];
      avg = currSum / (double)k;
      if (avg >= threshold)
      {
        count++;
      }
    }
    return count;
  }
};