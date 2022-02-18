class Solution
{
public:
  vector<string> subdomainVisits(vector<string> &cpdomains)
  {
    vector<string> ans;
    unordered_map<string, int> mp;
    for (int i = 0; i < cpdomains.size(); i++)
    {
      stringstream ss(cpdomains[i]);
      string str, num;
      while (ss >> num >> str)
      {
        if (mp.find(str) == mp.end())
          mp[str] = stoi(num);
        else
        {
          mp[str] += stoi(num);
        }
        for (int i = 0; i < str.length(); i++)
        {
          if (str[i] == '.')
          {
            string res = str.substr(i + 1, str.length() - i + 2);
            if (mp.find(res) == mp.end())
            {
              mp[res] = stoi(num);
            }
            else
            {
              mp[res] += stoi(num);
            }
          }
        }
      }
    }
    for (auto x : mp)
    {
      ans.push_back(to_string(x.second) + " " + x.first);
    }

    return ans;
  }
};