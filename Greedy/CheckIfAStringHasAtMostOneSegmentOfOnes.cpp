class Solution
{
public:
  bool checkOnesSegment(string s)
  {
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '1')
      {
        if (count == -1)
        {
          return false;
        }
        count++;
      }
      else
      {
        count = -1;
      }
    }
    return true;
  }
};