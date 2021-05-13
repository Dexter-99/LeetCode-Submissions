class Solution
{
public:
  int countCharacters(vector<string> &words, string chars)
  {
    int a[26] = {0};
    int count[26] = {0};
    int n = chars.length();
    for (int i = 0; i < n; i++)
      a[chars[i] - 'a']++;

    int res = 0;

    for (string word : words)
    {
      for (int i = 0; i < 26; i++)
        count[i] = 0;
      int len = word.length();
      for (int i = 0; i < len; i++)
      {
        count[word[i] - 'a']++;
      }
      bool flag = true;
      for (int i = 0; i < 26; i++)
      {
        if (count[i] && (count[i] > a[i]))
        {
          flag = false;
          break;
        }
      }

      res += flag ? word.length() : 0;
    }
    return res;
  }
};