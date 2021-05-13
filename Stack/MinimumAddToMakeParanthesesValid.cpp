class Solution
{
public:
  int minAddToMakeValid(string S)
  {
    stack<int> st;
    for (int i = 0; i < S.length(); i++)
    {
      if (S[i] == '(')
      {
        st.push(S[i]);
      }
      else
      {
        if (!st.empty() && st.top() == '(')
          st.pop();
        else
          st.push(S[i]);
      }
    }
    return st.size();
  }
};g