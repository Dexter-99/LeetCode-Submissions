class Solution
{
public:
  vector<vector<int>> transpose(vector<vector<int>> &A)
  {
    vector<vector<int>> v;
    vector<int> res;
    int n = A.size();
    int m = A[0].size();
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        res.push_back(A[j][i]);
      }

      v.push_back(res);
      res.clear();
    }
    return v;
    ;
  }
};