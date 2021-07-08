class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    if (nums.size() == 0)
      return 0;
    int tail[n];
    tail[0] = nums[0];
    int len = 1;
    for (int i = 1; i < n; i++)
    {
      if (nums[i] > tail[len - 1])
      {
        tail[len++] = nums[i];
      }
      else
      {
        auto it = lower_bound(tail, tail + len, nums[i]);
        int idx = it - tail;
        tail[idx] = nums[i];
      }
    }
    return len;
  }
};