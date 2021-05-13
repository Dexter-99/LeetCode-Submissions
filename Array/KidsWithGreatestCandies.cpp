class Solution
{
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
  {
    int _max = 0;
    int n = candies.size();
    for (int i = 0; i < n; i++)
    {
      if (candies[i] > _max)
      {
        _max = candies[i];
      }
    }
    vector<bool> v;

    for (int i = 0; i < n; i++)
    {
      if (extraCandies + candies[i] >= _max)
      {
        v.push_back(true);
      }
      else
      {
        v.push_back(false);
      }
    }
    return v;
  }
};