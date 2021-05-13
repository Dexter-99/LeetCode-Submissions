class Solution
{
public:
  vector<int> sortArrayByParity(vector<int> &A)
  {
    int n = A.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
      if (A[low] % 2 != 0 && A[high] % 2 == 0)
      {
        swap(A[low++], A[high--]);
      }
      else if (A[low] % 2 == 0)
      {
        low++;
      }
      else if (A[high] % 2 != 0)
      {
        high--;
      }
    }
    return A;
  }
};