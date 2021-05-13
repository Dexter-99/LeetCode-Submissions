class Solution
{
public:
  vector<int> getSumAbsoluteDifferences(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> res(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += nums[i];
    int sub = 0;
    for (int i = 0; i < n; i++)
    {
      res[i] = sum + (n - i) * (-nums[i]) + (i * nums[i]) - sub;
      sub += nums[i];
      sum -= nums[i];
    }
    return res;
  }
};