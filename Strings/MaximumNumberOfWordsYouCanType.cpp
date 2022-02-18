class Solution
{
public:
  int canBeTypedWords(string text, string brokenLetters)
  {
    unordered_set<char> h(brokenLetters.begin(), brokenLetters.end());

    stringstream ss(text);
    string str;
    int count = 0;
    while (ss >> str)
    {
      bool flag = true;
      for (int i = 0; i < str.length(); i++)
      {
        if (h.find(str[i]) != h.end())
        {
          flag = false;
          break;
        }
      }
      if (flag)
        count++;
    }
    return count;
  }
};