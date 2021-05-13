class Solution
{
public:
  int score(int low, int high, vector<int> &idx)
  {
    if (low == high - 1)
      return 1;

    int mid = idx[low];
    if (mid == high)
      return 2 * score(low + 1, high - 1, idx);
    return (score(low, mid, idx) + score(mid + 1, high, idx));
  }
  int scoreOfParentheses(string S)
  {
    int total = 0;
    int n = S.length();
    stack<int> st;
    vector<int> idx(n, 0);
    for (int i = 0; i < n; i++)
    {
      if (S[i] == ')')
      {
        int val = st.top();
        idx[val] = i;
        st.pop();
      }
      else
        st.push(i);
    }
    total = score(0, n - 1, idx);
    return total;
  }
};