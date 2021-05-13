class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {

    int n = digits.size();
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
      if (digits[i] != 9)
      {
        idx = i;
      }
    }
    if (idx == -1)
    {
      for (int i = 0; i < n; i++)
      {
        if (i == 0)
          digits[i] = 1;
        else
          digits[i] = 0;
      }
      digits.push_back(0);
    }
    else if (idx == n - 1)
    {
      digits[idx] += 1;
    }
    else
    {
      digits[idx] += 1;
      for (int i = idx + 1; i < n; i++)
      {
        digits[i] = 0;
      }
    }
    return digits;
  }
};