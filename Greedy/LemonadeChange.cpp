class Solution
{
public:
  bool lemonadeChange(vector<int> &bills)
  {
    int fives = 0, tens = 0, twentys = 0;
    int n = bills.size();
    for (int i = 0; i < n; i++)
    {
      if (bills[i] > 5)
      {
        int rem = bills[i] - 5;
        if (rem == 5)
        {
          if (fives > 0)
          {
            tens++;
            fives--;
          }
          else
          {
            return false;
          }
        }
        if (rem == 15)
        {
          if (tens > 0 && fives > 0)
          {
            tens--;
            fives--;
          }
          else if (tens == 0 && fives > 2)
          {
            fives -= 3;
          }
          else
            return false;
        }
      }
      else
      {
        fives++;
      }
    }
    return true;
  }
};