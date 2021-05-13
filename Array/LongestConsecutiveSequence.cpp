class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    unordered_set<int> h(nums.begin(), nums.end());
    int _max = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (h.find(nums[i] - 1) == h.end())
      {
        int len = 1;
        int num = nums[i];
        while (h.find(num + 1) != h.end())
        {
          len++;
          num += 1;
        }
        _max = max(_max, len);
      }
    }

    return _max;
  }
};