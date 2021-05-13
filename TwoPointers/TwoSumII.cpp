#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    vector<int> v;
    int low = 0;
    int high = numbers.size() - 1;
    while (low < high)
    {
      if (numbers[low] + numbers[high] == target)
        break;
      else if (numbers[low] + numbers[high] > target)
        high--;
      else
        low++;
    }
    v.push_back(low + 1);
    v.push_back(high + 1);
    return v;
  }
};