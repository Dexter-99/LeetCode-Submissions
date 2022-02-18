class Solution
{
public:
  vector<int> numberOfLines(vector<int> &widths, string s)
  {
    int sum = 0, count = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (sum + widths[s[i] - 'a'] <= 100)
      {
        sum = sum + widths[s[i] - 'a'];
      }
      else
      {
        // cout<<sum<<endl;
        count++;
        sum = widths[s[i] - 'a'];
      }
    }
    count++;

    return {count, sum};
  }
};