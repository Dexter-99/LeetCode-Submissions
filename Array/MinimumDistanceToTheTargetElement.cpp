class Solution
{
public:
  int getMinDistance(vector<int> &nums, int target, int start)
  {

    int n = nums.size();
    int _min = n;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == target)
        _min = min(_min, abs(i - start));
    }
    return _min;
  }
};