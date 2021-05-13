class Solution
{
public:
  vector<int> arrayRankTransform(vector<int> &arr)
  {

    vector<int> list = arr;
    sort(list.begin(), list.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < list.size(); i++)
    {
      if (mp.find(list[i]) == mp.end())
        mp[list[i]] = mp.size() + 1;
    }
    for (int i = 0; i < arr.size(); i++)
      arr[i] = mp[arr[i]];
    return arr;
  }
};