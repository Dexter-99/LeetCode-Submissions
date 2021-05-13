class Solution
{
public:
  double averageWaitingTime(vector<vector<int>> &customers)
  {

    long long currTime = customers[0][0] + customers[0][1];
    long long waitTime = customers[0][1];
    int n = customers.size();
    for (int i = 1; i < n; i++)
    {
      if (currTime < customers[i][0])
        currTime = customers[i][0];
      waitTime += currTime - customers[i][0] + customers[i][1];
      currTime += customers[i][1];
    }
    return waitTime / (double)n;
  }
};