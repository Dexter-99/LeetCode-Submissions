class Solution
{
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
  {
    stack<int> st;
    int curr = 0;
    int n = pushed.size();
    for (int i = 0; i < n; i++)
    {
      st.push(pushed[i]);
      while (!st.empty() && st.top() == popped[curr])
      {
        st.pop();
        curr++;
      }
    }
    return curr == n;
  }
};