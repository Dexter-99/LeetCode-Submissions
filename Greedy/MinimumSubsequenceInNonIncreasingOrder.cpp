class Solution
{
public:
  vector<int> minSubsequence(vector<int> &nums)
  {
    int sum = 0;
    int n = nums.size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
    }
    sum = sum / 2;
    vector<int> res;
    sort(nums.begin(), nums.end(), greater<int>());

    for (int i = 0; i < n; i++)
    {
      total += nums[i];
      res.push_back(nums[i]);
      if (total > sum)
        break;
    }
    return res;
  }
};