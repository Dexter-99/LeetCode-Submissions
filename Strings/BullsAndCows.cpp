class Solution
{
public:
  string getHint(string secret, string guess)
  {
    vector<int> a1(10, 0);
    vector<int> a2(10, 0);
    int bulls = 0, cows = 0;
    for (int i = 0; i < secret.size(); i++)
    {
      if (secret[i] == guess[i])
      {
        bulls++;
      }
      else
      {
        a1[secret[i] - '0']++;
        a2[guess[i] - '0']++;
      }
    }
    for (int i = 0; i < 10; i++)
    {
      cows += min(a1[i], a2[i]);
    }
    string ans = to_string(bulls) + "A" + to_string(cows) + "B";
    return ans;
  }
};