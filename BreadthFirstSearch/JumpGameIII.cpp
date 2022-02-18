class Solution
{
public:
  bool canReach(vector<int> &arr, int start)
  {
    int n = arr.size();
    queue<int> q;
    unordered_set<int> h;
    q.push(start);
    h.insert(start);
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        int curr = q.front();
        q.pop();
        if (arr[curr] == 0)
          return true;

        if (curr + arr[curr] < n && h.find(curr + arr[curr]) == h.end())
        {
          q.push(curr + arr[curr]);
          h.insert(curr + arr[curr]);
        }
        if (curr - arr[curr] >= 0 && h.find(curr - arr[curr]) == h.end())
        {
          q.push(curr - arr[curr]);
          h.insert(curr - arr[curr]);
        }
      }
    }
    return false;
  }
};