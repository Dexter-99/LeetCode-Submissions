class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> list(n, 0);
    stack<int> st;
    st.push(n - 1);
    list[n - 1] = -1;
    for (int i = 2 * n - 2; i >= 0; i--)
    {
      while (!st.empty() && nums[st.top()] <= nums[i % n])
      {
        st.pop();
      }
      int val = st.empty() ? -1 : nums[st.top()];
      list[i % n] = val;
      st.push(i % n);
    }
    return list;
  }
};