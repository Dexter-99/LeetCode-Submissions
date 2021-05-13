class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    int res = nums[0];
    int count = 1;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
      if (nums[i] != res)
      {
        count--;
      }
      else
        count++;
      if (count == 0)
      {
        res = nums[i];
        count = 1;
      }
    }
    return res;
  }
};