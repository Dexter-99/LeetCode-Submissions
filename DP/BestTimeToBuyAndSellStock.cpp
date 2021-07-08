class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int currMax = 0;
    int currMin = prices[0];
    for (int i = 1; i < n; i++)
    {
      currMax = max(currMax, prices[i] - currMin);
      currMin = min(prices[i], currMin);
    }
    return currMax;
  }
};