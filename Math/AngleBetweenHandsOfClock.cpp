class Solution
{
public:
  double angleClock(int hour, int minutes)
  {
    double h = (hour + minutes / 60.0) * 30.0;
    double m = minutes * 6.0;
    double ans = abs(h - m);

    return min(ans, (360 - ans));
  }
};