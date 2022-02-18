class Solution
{
public:
  vector<int> numMovesStones(int a, int b, int c)
  {

    if (abs(a - b) == 1 && abs(b - c) == 1)
    {
      return {0, 0};
    }
    vector<int> list = {a, b, c};
    sort(list.begin(), list.end());
    a = list[0], b = list[1], c = list[2];

    int a_b = b - a;
    int b_c = c - b;

    int ans1 = 0, ans2 = 0;
    if (a_b == 2 || b_c == 2)
    {
      ans1 = 1;
    }
    else
    {
      ans1 += (a_b == 1 ? 0 : 1);
      ans1 += (b_c == 1 ? 0 : 1);
    }
    ans2 += a_b + b_c - 2;
    return {ans1, ans2};
  }
};