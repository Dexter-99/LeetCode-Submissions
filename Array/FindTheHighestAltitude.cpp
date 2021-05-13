class Solution
{
public:
  int largestAltitude(vector<int> &gain)
  {
    int res = 0;
    int n = gain.size();
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
      res = max(res, gain[i] + curr);
      curr = gain[i] + curr;
    }
    return res;
  }
};