class Solution
{
public:
  int minJumps(vector<int> &arr)
  {
    int n = arr.size();
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
      mp[arr[i]].push_back(i);
    }
    int count = 0;

    queue<int> q;
    unordered_set<int> h;
    q.push(0);
    h.insert(0);
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        int curr = q.front();
        q.pop();
        if (curr == n - 1)
          return count;
        if (curr + 1 < n && h.find(curr + 1) == h.end())
        {
          q.push(curr + 1);
          h.insert(curr + 1);
        }
        if (curr - 1 >= 0 && h.find(curr - 1) == h.end())
        {
          q.push(curr - 1);
          h.insert(curr - 1);
        }
        for (int i = 0; i < mp[arr[curr]].size(); i++)
        {
          if (mp[arr[curr]][i] != curr && h.find(mp[arr[curr]][i]) == h.end())
          {
            q.push(mp[arr[curr]][i]);
            h.insert(mp[arr[curr]][i]);
          }
        }
        mp.erase(arr[curr]);
      }
      count++;
    }
    return -1;
  }
};