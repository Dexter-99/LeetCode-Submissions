class Solution
{
public:
  int maxIceCream(vector<int> &costs, int coins)
  {
    sort(costs.begin(), costs.end());
    int count = 0;
    int n = costs.size();
    for (int i = 0; i < n; i++)
    {
      if (coins >= costs[i])
      {
        coins -= costs[i];
        count++;
      }
      else
        break;
    }
    return count;
  }
};