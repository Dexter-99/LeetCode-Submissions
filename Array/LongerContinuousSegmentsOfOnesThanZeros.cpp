class Solution
{
public:
  bool checkZeroOnes(string s)
  {
    int z = 0, o = 0, cz = 0, co = 0, n = s.length();
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '1')
      {
        cz = 0;
        co++;
        o = max(co, o);
      }
      else
      {
        co = 0;
        cz++;
        z = max(cz, z);
      }
    }
    return o > z;
  }
};