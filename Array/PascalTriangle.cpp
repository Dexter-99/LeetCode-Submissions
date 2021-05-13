class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {

    vector<vector<int>> list(numRows);
    for (int i = 0; i < numRows; i++)
    {
      list[i].resize(i + 1);
      list[i][0] = 1;
      list[i][i] = 1;
      for (int j = 1; j < i; j++)
      {
        list[i][j] = list[i - 1][j - 1] + list[i - 1][j];
      }
    }
    return list;
  }
};