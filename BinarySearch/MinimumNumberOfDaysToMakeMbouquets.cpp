class Solution
{
public:
  bool isValid(vector<int> &day, int m, int k, int maxVal)
  {
    int count = 0;
    int n = day.size();
    int days = 0;
    for (int i = 0; i < n; i++)
    {
      if (day[i] <= maxVal)
      {
        days++;
      }
      else
      {
        days = 0;
      }
      if (days == k)
      {
        count++;

        days = 0;
      }
    }
    return count >= m;
  }
  int minDays(vector<int> &bloomDay, int m, int k)
  {
    if (m * k > bloomDay.size())
      return -1;
    int _min = INT32_MAX, _max = bloomDay[0];
    for (auto x : bloomDay)
    {
      _min = min(_min, x);
      _max = max(_max, x);
    }
    int low = _min, high = _max;
    int res = -1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (isValid(bloomDay, m, k, mid))
      {
        res = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return res;
  }
};