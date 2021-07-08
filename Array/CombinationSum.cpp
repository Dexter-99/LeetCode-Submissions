class Solution
{
public:
  vector<vector<int>> list;
  void combination(vector<int> &candidates, int target, int idx, int n, vector<int> &res)
  {
    if (idx == n)
    {
      if (target == 0)
      {
        list.push_back(res);
      }
      return;
    }

    if (candidates[idx] <= target)
    {
      res.push_back(candidates[idx]);
      combination(candidates, target - candidates[idx], idx, n, res);
      res.pop_back();
    }
    combination(candidates, target, idx + 1, n, res);
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<int> res;
    combination(candidates, target, 0, candidates.size(), res);
    return list;
  }
};