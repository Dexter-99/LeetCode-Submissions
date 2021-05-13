class Solution
{
public:
  int maxDepth(string s)
  {
    stack<char> st;
    int n = s.length();
    int _max = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(')
      {
        st.push(s[i]);
        int len = st.size();
        _max = max(_max, len);
      }
      else if (s[i] == ')')
      {
        if (!st.empty())
        {
          st.pop();
        }
      }
    }
    return _max;
  }
};