class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int res = 0;
    int n = heights.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && heights[st.top()] >= heights[i])
      {
        int val = st.top();
        st.pop();
        int curr = heights[val] * (st.empty() ? i : (i - st.top() - 1));
        res = max(res, curr);
      }
      st.push(i);
    }
    while (!st.empty())
    {
      int val = st.top();
      st.pop();
      int curr = heights[val] * (st.empty() ? n : (n - st.top() - 1));
      res = max(res, curr);
    }
    return res;
  }
};