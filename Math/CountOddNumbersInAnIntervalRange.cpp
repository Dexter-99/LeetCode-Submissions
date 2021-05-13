class Solution
{
public:
  int countOdds(int low, int high)
  {
    int count1 = (low & 1) ? (low / 2 + 1) : (low / 2);
    int count2 = (high & 1) ? (high / 2 + 1) : (high / 2);
    if (low & 1)
      return (count2 - count1 + 1);
    return count2 - count1;
  }
};