class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0, high = n - 1;
    while (low < m && high >= 0)
    {
      if (matrix[low][high] == target)
      {
        return true;
      }
      else if (matrix[low][high] > target)
      {
        high = high - 1;
      }
      else
      {
        low = low + 1;
      }
    }
    return false;
  }
};