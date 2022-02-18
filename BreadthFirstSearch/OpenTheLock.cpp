class Solution
{
public:
  int openLock(vector<string> &deadends, string target)
  {
    unordered_set<string> dead;
    for (int i = 0; i < deadends.size(); i++)
    {
      dead.insert(deadends[i]);
    }

    queue<string> q;
    unordered_set<string> visited;
    if (dead.find("0000") == dead.end())
      q.push("0000");
    visited.insert("0000");
    int steps = 0;
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        string curr = q.front();
        q.pop();
        // cout<<curr<<" "<<d<<endl;
        if (curr == target)
        {
          return steps;
        }
        for (int i = 0; i < curr.length(); i++)
        {

          string tmp1 = curr, tmp2 = curr;
          tmp1[i] = (tmp1[i] - '0' + 1) % 10 + '0';
          tmp2[i] = (tmp2[i] - '0' - 1 + 10) % 10 + '0';
          // cout<<tmp1<<" "<<tmp2<<endl;

          if (dead.find(tmp1) == dead.end() && visited.find(tmp1) == visited.end())
          {
            q.push(tmp1);
            visited.insert(tmp1);
          }

          if (dead.find(tmp2) == dead.end() && visited.find(tmp2) == visited.end())
          {
            q.push(tmp2);
            visited.insert(tmp2);
          }
        }
      }
      steps++;
    }

    return -1;
  }
};