class Solution
{
public:
  int lastStoneWeight(vector<int> &stones)
  {
    priority_queue<int> pq;
    int len = stones.size();
    for (int i = 0; i < len; i++)
    {
      pq.push(stones[i]);
    }
    while (pq.size() > 1)
    {
      int res = pq.top();
      pq.pop();
      res -= pq.top();
      pq.pop();
      pq.push(res);
    }
    return pq.top();
  }
};