class Solution
{
public:
  bool isValid(vector<int> &piles, int h, int maxH)
  {
    int count = 0;

    for (int i = 0; i < piles.size(); i++)
    {

      count += piles[i] / maxH;
      if (piles[i] % maxH != 0)
        count++;
    }

    return count <= h;
  }

  int minEatingSpeed(vector<int> &piles, int h)
  {
    int _max = 0;
    for (auto x : piles)
    {
      _max = max(_max, x);
    }

    int low = 1, high = _max, res = piles[0];
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (isValid(piles, h, mid))
      {
        res = mid;
        high = mid - 1;
      }
      else
      {

        low = mid + 1;
      }
    }
    return res;
  }
};