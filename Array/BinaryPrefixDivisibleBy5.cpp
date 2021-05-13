class Solution
{
public:
  vector<bool> prefixesDivBy5(vector<int> &A)
  {

    int n = A.size();
    int res = 0;
    vector<bool> list;
    for (int i = 0; i < n; i++)
    {
      res = (res << 1) + A[i];
      list.push_back(!(res % 5));
      res = res % 5;
    }
    return list;
  }
};