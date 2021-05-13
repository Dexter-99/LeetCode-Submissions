class Solution
{
public:
  vector<int> findDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> list;
    for (int i = 0; i < n; i++)
    {
      int idx = abs(nums[i]) - 1;
      if (nums[idx] < 0)
        list.push_back(idx + 1);
      nums[idx] *= -1;
    }
    return list;
  }
};