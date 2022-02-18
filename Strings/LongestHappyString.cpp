class Solution
{
public:
  string longestDiverseString(int a, int b, int c)
  {
    string res = "";
    priority_queue<pair<int, char>> pq;
    pq.push({a, 'a'});
    pq.push({b, 'b'});
    pq.push({c, 'c'});
    for (int i = 0; i < a + b + c; i++)
    {
      pair<int, char> curr = pq.top();
      pq.pop();
      if (res.length() >= 2 && curr.second == res[res.length() - 1] && curr.second == res[res.length() - 2])
      {
        if (pq.top().first == 0)
        {
          return res;
        }
        pair<int, char> next = pq.top();
        pq.pop();

        res += next.second;
        pq.push({next.first - 1, next.second});
        pq.push(curr);
      }
      else
      {
        res += curr.second;
        pq.push({curr.first - 1, curr.second});
      }
    }
    return res;
  }
};