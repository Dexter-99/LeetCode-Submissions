class Solution
{
public:
  vector<string> buildArray(vector<int> &target, int n)
  {
    vector<string> list;
    int len = target.size();
    int val = 1;
    for (int i = 0; i < len; i++)
    {
      list.push_back("Push");
      if (target[i] != val)
      {
        list.push_back("Pop");
        i--;
      }
      val++;
    }
    return list;
  }
};