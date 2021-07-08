class Solution
{
public:
  vector<double> sampleStats(vector<int> &count)
  {
    double _min = 255, _max = 0, median = 0, mode = 0, mean = 0;
    double total = 0;
    int c = 0;
    for (int i = 0; i < 256; i++)
    {
      if (count[i])
      {
        _min = min(_min, (double)i);
        _max = max(_max, (double)i);
        total += (long long)i * count[i];
        c += count[i];
        if (count[i] >= count[mode])
        {
          mode = i;
        }
      }
    }
    long long ctr = 0;
    cout << c << endl;
    for (int i = 0; i < 256; i++)
    {
      if (count[i])
      {
        cout << i << endl;
        if (c & 1)
        {
          if ((long long)count[i] + ctr >= (c / 2 + 1))
          {
            median = i;
            break;
          }
        }
        else
        {
          if ((long long)count[i] + ctr > (c / 2))
          {
            if (median != 0)
            {
              median = (median + i) / 2.0;
            }
            else
              median = (i + i) / 2.0;
            break;
          }
          else if ((long long)ctr + count[i] == (c / 2))
          {
            median += i;
          }
        }
        ctr += count[i];
        cout << ctr << endl;
      }
    }
    mean = (total) / c;
    return {_min, _max, mean, median, mode};
  }
};