class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int max1 = INT32_MIN;
    int max2 = INT32_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (nums[i] >= max1)
      {
        max2 = max1;
        max1 = nums[i];
      }
      else if (nums[i] >= max2 && nums[i] < max1)
      {
        max2 = nums[i];
      }
    }
    return (max2 - 1) * (max1 - 1);
  }
};