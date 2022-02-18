class Solution
{
public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
  {
    int val = tomatoSlices - 2 * cheeseSlices;
    if (val % 2 != 0)
    {
      return {};
    }
    int ans1 = val / 2;
    int ans2 = cheeseSlices - ans1;
    if (ans1 < 0 || ans2 < 0)
      return {};
    return {ans1, ans2};
  }
};

// 4a+2b=tomatoSlices;
// a+b=cheeseSlices;
// b=cheeseSlices-a;
// 2a=tomatoSlices-2*(cheeseSlices)