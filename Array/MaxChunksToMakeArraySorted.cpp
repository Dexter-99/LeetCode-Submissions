class Solution
{
public:
  int maxChunksToSorted(vector<int> &arr)
  {
    int chunks = 0, _max = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
      _max = max(_max, arr[i]);
      if (_max == i)
      {
        chunks++;
      }
    }
    return chunks;
  }
};