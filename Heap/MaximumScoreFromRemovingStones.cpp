class Solution
{
public:
  int maximumScore(int a, int b, int c)
  {
    priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int count = 0;

    while (pq.size() > 1)
    {
      int u, v;
      u = pq.top();
      pq.pop();
      v = pq.top();
      pq.pop();
      if (--u > 0)
        pq.push(u);
      if (--v > 0)
        pq.push(v);
      count++;
    }
    return count;
  }
};inte