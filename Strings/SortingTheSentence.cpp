class Solution
{
public:
  string sortSentence(string s)
  {
    stringstream ss(s);
    string str;
    vector<string> list(10);
    int count = 0;
    while (ss >> str)
    {
      int idx = str[str.length() - 1] - '0' - 1;
      list[idx] = str.substr(0, str.length() - 1);
      count++;
    }
    string res = "";
    res += list[0];
    for (int i = 1; i < count; i++)
    {
      res += " " + list[i];
    }
    return res;
  }
};