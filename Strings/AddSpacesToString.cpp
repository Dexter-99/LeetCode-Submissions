class Solution
{
public:
  string addSpaces(string s, vector<int> &spaces)
  {
    int j = 0;
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
      if (j < spaces.size() && i == spaces[j])
      {

        j++;
        res += " ";
        res += s[i];
      }
      else
      {
        res += s[i];
      }
    }
    return res;
  }
};