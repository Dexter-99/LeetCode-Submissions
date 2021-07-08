class Solution
{
public:
  int numSub(string s)
  {
    long long count = 0;
    long long total = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '1')
        count++;
      else
      {
        long long val = (count % mod * (count + 1) % mod) % mod;
        val = (val / 2) % mod;
        total = (total + val) % mod;
        count = 0;
      }
    }
    long long val = (count % mod * (count + 1) % mod) % mod;
    val = (val / 2) % mod;
    total = (total + val) % mod;
    return total;
  }
};