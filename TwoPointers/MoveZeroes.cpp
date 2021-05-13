#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int low = 0;
    int curr = 0;
    int n = nums.size();
    for (curr = 0; curr < n; curr++)
    {
      if (nums[curr] != 0)
      {
        swap(nums[curr], nums[low++]);
      }
    }
  }
};