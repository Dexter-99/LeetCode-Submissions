class Solution
{
public:
  int smallestRangeI(vector<int> &A, int K)
  {
    int _max = 0, _min = 10000;
    for (int i = 0; i < A.size(); i++)
    {
      _max = max(_max, A[i]);
      _min = min(_min, A[i]);
    }
    if (_max - _min - 2 * K < 0)
      return 0;
    return _max - _min - 2 * K;
  }
};