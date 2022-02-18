class Solution
{
public:
  int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
  {
    int ans = 0;
    int n = arr1.size();
    int max1 = INT32_MIN;
    int min1 = INT32_MAX;
    int max2 = INT32_MIN;
    int min2 = INT32_MAX;
    int max3 = INT32_MIN;
    int min3 = INT32_MAX;
    int max4 = INT32_MIN;
    int min4 = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
      max1 = max(max1, arr1[i] + arr2[i] + i);
      min1 = min(min1, arr1[i] + arr2[i] + i);
      max2 = max(max2, arr1[i] - arr2[i] + i);
      min2 = min(min2, arr1[i] - arr2[i] + i);
      max3 = max(max3, arr1[i] + arr2[i] - i);
      min3 = min(min3, arr1[i] + arr2[i] - i);
      max4 = max(max4, arr1[i] - arr2[i] - i);
      min4 = min(min4, arr1[i] - arr2[i] - i);
    }
    return max({(max1 - min1), (max2 - min2), (max3 - min3), (max4 - min4)});
  }
};