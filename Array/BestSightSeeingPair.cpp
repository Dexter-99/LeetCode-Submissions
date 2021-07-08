class Solution
{
public:
  int maxScoreSightseeingPair(vector<int> &values)
  {
    int _max = values[0] + 0;

    int ans = 0;
    for (int i = 1; i < values.size(); i++)
    {
      // cout<<_min<<endl;
      ans = max(ans, values[i] - i + _max);
      _max = max(_max, values[i] + i);
    }
    return ans;
  }
};