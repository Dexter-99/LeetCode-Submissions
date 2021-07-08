class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> list;
    for (int i = 0; i < n - 2; i++)
    {
      if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
      {
        int target = -1 * nums[i];
        int low = i + 1, high = n - 1;
        while (low < high)
        {
          if (nums[low] + nums[high] == target)
          {
            list.push_back({-1 * target, nums[low], nums[high]});
            while (low < high && nums[low] == nums[low + 1])
              low++;
            while (low < high && nums[high] == nums[high - 1])
              high--;
            low++;
            high--;
          }
          else if (nums[low] + nums[high] > target)
          {
            high--;
          }
          else
          {
            low++;
          }
        }
      }
    }
    return list;
  }
};