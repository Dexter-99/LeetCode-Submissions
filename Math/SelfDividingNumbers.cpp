class Solution
{
public:
  vector<int> selfDividingNumbers(int left, int right)
  {
    vector<int> list;
    for (int i = left; i <= right; i++)
    {
      int num = i;
      bool flag = true;
      while (num)
      {
        int dig = num % 10;
        if (dig == 0 || i % dig != 0)
        {
          flag = false;
          break;
        }
        num /= 10;
      }
      if (flag)
        list.push_back(i);
    }
    return list;
  }
};