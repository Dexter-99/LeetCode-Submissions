class Solution
{
public:
  int longestOnes(vector<int> &A, int K)
  {
    int maxCount = 0;
    int zero = 0;
    int s = 0;
    int n = A.size();
    for (int e = 0; e < n; e++)
    {
      if (A[e] == 0)
      {
        zero++;
      }
      while (zero > K)
      {
        if (A[s] == 0)
        {
          zero--;
        }
        s++;
      }
      maxCount = max(maxCount, e - s + 1);
    }
    return maxCount;
  }
};