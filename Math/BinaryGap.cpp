class Solution
{
public:
  int binaryGap(int n)
  {
    int pos = 0;
    int last = -1;
    int _max = 0;
    while (n > 0)
    {
      if (n & 1)
      {
        if (last != -1)
        {
          _max = max(_max, pos - last);
        }
        last = pos;
      }
      pos++;
      n >>= 1;
    }
    return _max;
  }
};