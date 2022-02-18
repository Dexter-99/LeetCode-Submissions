class Solution
{
public:
  int minMutation(string start, string end, vector<string> &bank)
  {
    unordered_set<string> h;
    for (int i = 0; i < bank.size(); i++)
    {
      h.insert(bank[i]);
    }

    queue<string> q;
    unordered_set<string> visited;
    q.push(start);
    visited.insert(start);
    int count = 0;
    char ch[4] = {'A', 'C', 'G', 'T'};
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        string curr = q.front();
        q.pop();
        if (curr == end)
        {
          return count;
        }
        for (int i = 0; i < 8; i++)
        {
          for (int k = 0; k < 4; k++)
          {
            char c = curr[i];
            curr[i] = ch[k];
            if (h.find(curr) != h.end() && visited.find(curr) == visited.end())
            {
              q.push(curr);
              visited.insert(curr);
            }
            curr[i] = c;
          }
        }
      }
      count++;
    }
    return -1;
  }
};