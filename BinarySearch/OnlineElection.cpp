class TopVotedCandidate
{
public:
  vector<int> leading;
  vector<int> tms;
  TopVotedCandidate(vector<int> &persons, vector<int> &times)
  {
    unordered_map<int, int> mp;
    int curr = persons[0];
    int currMax = 1;
    mp[curr]++;
    leading.push_back(persons[0]);
    for (int i = 1; i < persons.size(); i++)
    {
      mp[persons[i]]++;
      if (mp[persons[i]] >= currMax)
      {
        currMax = mp[persons[i]];
        curr = persons[i];
      }
      leading.push_back(curr);
    }
    tms = times;
  }

  int q(int t)
  {
    int low = 0, high = tms.size() - 1;
    int res = tms[high];
    while (low <= high)
    {
      int mid = low + ((high - low) >> 1);
      if (tms[mid] <= t)
      {
        res = mid;
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    return leading[res];
  }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */