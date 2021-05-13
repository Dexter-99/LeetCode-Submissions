class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    for (int i = 0; i <= high;)
    {
      if (nums[i] == 0)
      {
        swap(nums[i++], nums[low++]);
      }
      else if (nums[i] == 1)
        i++;
      else if (nums[i] == 2)
      {
        swap(nums[i], nums[high--]);
      }
    }
  }
};