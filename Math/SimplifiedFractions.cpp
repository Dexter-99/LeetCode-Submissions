class Solution
{
public:
  vector<string> simplifiedFractions(int n)
  {
    vector<string> res;
    for (int i = 1; i < n; i++)
    {
      for (int j = i + 1; j <= n; j++)
      {
        if (gcd(i, j) == 1)
        {
          string str = to_string(i) + "/" + to_string(j);
          res.push_back(str);
        }
      }
    }
    return res;
  }
};