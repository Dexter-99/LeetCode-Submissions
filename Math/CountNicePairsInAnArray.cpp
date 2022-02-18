class Solution
{
public:
  int countNicePairs(vector<int> &nums)
  {
    int n = nums.size();
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      int rev = 0;
      int num = nums[i];
      while (num != 0)
      {
        rev = rev * 10 + (num % 10);
        num /= 10;
      }
      ans = (ans + mp[nums[i] - rev]++) % 1000000007;
    }
    return ans;
  }
};