class Solution
{
  static bool compare(vector<int> a1, vector<int> a2)
  {
    return a1[1] > a2[1];
  }

public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
  {
    sort(boxTypes.begin(), boxTypes.end(), compare);
    int sum = 0;
    int len = boxTypes.size();
    for (int i = 0; i < len; i++)
    {
      int boxes = boxTypes[i][0];
      int units = boxTypes[i][1];
      if (boxes <= truckSize)
      {
        truckSize -= boxes;
        sum += boxes * units;
      }
      else
      {
        sum += truckSize * units;
        truckSize = 0;
      }
    }

    return sum;
  }
};