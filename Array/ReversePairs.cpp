class Solution
{
public:
  int merge(vector<int> &nums, int low, int mid, int high)
  {
    int count = 0, k = 0;
    int i, j = mid + 1;
    for (i = low; i <= mid; i++)
    {
      while (j <= high && nums[i] > (2 * (long long)nums[j]))
      {
        j++;
      }
      count += (j - (mid + 1));
    }
    int len = high - low + 1;
    int temp[len];
    i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
      if (nums[i] <= nums[j])
        temp[k++] = nums[i++];
      else
        temp[k++] = nums[j++];
    }
    while (i <= mid)
      temp[k++] = nums[i++];
    while (j <= high)
      temp[k++] = nums[j++];
    for (int i = low; i <= high; i++)
    {
      nums[i] = temp[i - low];
    }
    return count;
  }
  int mergeSort(vector<int> &nums, int low, int high)
  {
    if (low >= high)
      return 0;
    int mid = low + (high - low) / 2;
    int count = mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += merge(nums, low, mid, high);
    return count;
  }
  int reversePairs(vector<int> &nums)
  {
    int n = nums.size();
    return mergeSort(nums, 0, n - 1);
  }
};