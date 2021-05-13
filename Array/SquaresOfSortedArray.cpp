class Solution
{
public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> v(n, 0);
    int low = 0;
    int high = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
      if (abs(nums[low]) > abs(nums[high]))
      {
        v[i] = nums[low] * nums[low];
        low++;
      }
      else
      {
        v[i] = nums[high] * nums[high];
        high--;
      }
    }
    return v;
  }
};