class Solution
{
public:
  int maxVowels(string s, int k)
  {
    int n = s.length();
    int count = 0;
    string vowels = "aeiou";
    int curr_sum = 0;
    for (int i = 0; i < k; i++)
    {
      if (vowels.find(s[i]) != string::npos)
        curr_sum++;
    }
    int max_sum = curr_sum;
    for (int i = k; i < n; i++)
    {
      if (vowels.find(s[i - k]) != string::npos)
        curr--;
      if (vowels.find(s[i]) != string::npos)
        curr++;
      max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
  }
};