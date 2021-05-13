class Solution
{
public:
  int minCostToMoveChips(vector<int> &position)
  {
    int n = position.size();
    int o = 0, e = 0;
    ;
    for (int i = 0; i < n; i++)
    {
      if (position[i] & 1)
        o++;
      else
        e++;
    }
    return min(o, e);
  }
};