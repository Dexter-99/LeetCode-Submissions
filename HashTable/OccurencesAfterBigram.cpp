class Solution
{
public:
  vector<string> findOcurrences(string text, string first, string second)
  {
    stringstream ss(text);
    string str = "", res = "";
    vector<string> list;
    while (ss >> res)
    {
      if (str == (first + second))
      {
        list.push_back(res);
        str = "";
      }
      if (res == first)
      {
        str = res;
      }
      else if (str != "" && res == second)
      {
        str += res;
      }
      else
      {
        str = "";
      }
    }
    return list;
  }
};