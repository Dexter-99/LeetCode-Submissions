class Solution
{
public:
  string reverseWords(string s)
  {
    stringstream ss(s);
    string res = "", str;
    while (ss >> str)
    {
      res = str + " " + res;
    }
    return res.substr(0, res.length() - 1);
  }
};