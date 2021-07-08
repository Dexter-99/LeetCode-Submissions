class Solution
{
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration)
  {
    int sum = duration;
    int curr = timeSeries[0] + duration - 1;
    for (int i = 1; i < timeSeries.size(); i++)
    {
      if (timeSeries[i] <= curr)
      {
        sum -= abs(timeSeries[i] - curr) + 1;
        sum += duration;
        curr = timeSeries[i] + duration - 1;
      }
      else
      {
        sum += duration;
        curr = timeSeries[i] + duration - 1;
      }
    }
    return sum;
  }
};