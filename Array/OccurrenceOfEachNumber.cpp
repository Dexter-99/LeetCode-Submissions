vector<int> Solution::findOccurences(vector<int> &A)
{
  map<int, int> mp;
  for (int i = 0; i < A.size(); i++)
  {
    mp[A[i]]++;
  }
  vector<int> ans;
  for (auto x : mp)
  {
    ans.push_back(x.second);
  }
  return ans;
}
