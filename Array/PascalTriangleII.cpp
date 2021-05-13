class Solution
{
public:
  vector<int> getRow(int rowIndex)
  {
    vector<int> list;
    long long res = 1;
    list.push_back(res);
    for (int i = 1; i <= rowIndex; i++)
    {
      res = res * (rowIndex - i + 1) / i;
      list.push_back((int)res);
    }
    return list;
  }
};