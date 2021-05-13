class Solution
{
public:
  int dominantIndex(vector<int> &nums)
  {
    int smax = INT32_MIN, _max = INT32_MIN;
    int n = nums.size();
    if (n == 1)
      return 0;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] > _max)
      {
        smax = _max;
        _max = nums[i];
        idx = i;
      }
      else if (nums[i] > smax)
      {
        smax = nums[i];
      }
    }
    if (_max >= 2 * smax)
      return idx;
    return -1;
  }
};