class Solution
{
public:
  int numberOfBeams(vector<string> &bank)
  {
    int ans = 0;
    int n = bank.size();
    int prev = 0;
    for (int i = 0; i < bank[0].size(); i++)
    {
      if (bank[0][i] == '1')
        prev++;
    }
    for (int i = 1; i < n; i++)
    {
      int curr = 0;
      for (int j = 0; j < bank[i].size(); j++)
      {
        if (bank[i][j] == '1')
        {
          ans += prev;
          curr++;
        }
      }
      if (curr != 0)
        prev = curr;
    }
    return ans;
  }
};