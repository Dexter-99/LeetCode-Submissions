class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {

    unordered_map<int, int> mp;
    vector<int> list;
    stack<int> st;
    st.push(nums2.size() - 1);
    mp[nums2[nums2.size() - 1]] = -1;
    for (int i = nums2.size() - 2; i >= 0; i--)
    {
      while (!st.empty() && nums2[st.top()] <= nums2[i])
      {
        st.pop();
      }
      int val = st.empty() ? -1 : nums2[st.top()];
      mp[nums2[i]] = val;
      st.push(i);
    }
    for (int i = 0; i < nums1.size(); i++)
    {
      list.push_back(mp[nums1[i]]);
    }
    return list;
  }
};