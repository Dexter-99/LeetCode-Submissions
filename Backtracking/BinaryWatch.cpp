class Solution
{
public:
  void solve(vector<string> &ans, int idx, int k, vector<int> &watch, int hh, int mm)
  {
    if (k == 0)
    {
      // cout<<hh<<" "<<mm<<endl;

      if (hh < 12 && mm < 60)
      {
        string h = to_string(hh);
        string m = to_string(mm);
        if (mm < 10)
        {
          m = "0" + m;
        }
        ans.push_back(h + ":" + m);
      }
      return;
    }

    for (int i = idx; i < watch.size(); i++)
    {
      if (i >= 0 && i <= 3)
      {
        hh += watch[i];
      }
      else
      {
        mm += watch[i];
      }
      solve(ans, i + 1, k - 1, watch, hh, mm);
      if (i >= 0 && i <= 3)
      {
        hh -= watch[i];
      }
      else
      {
        mm -= watch[i];
      }
    }
  }
  vector<string> readBinaryWatch(int turnedOn)
  {

    vector<int> watch = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
    vector<string> ans;
    solve(ans, 0, turnedOn, watch, 0, 0);
    return ans;

    //         Iterative Solution

    // vector<string> ans;
    // for(int hh=0;hh<12;hh++)
    // {
    //     for(int mm=0;mm<60;mm++ )
    //     {
    //         if(__builtin_popcount(hh) + __builtin_popcount(mm)==turnedOn)
    //         {
    //             string h=to_string(hh);
    //             string m=to_string(mm);
    //             if(mm<10)
    //                 m="0"+m;
    //             ans.push_back(h+":"+m);
    //         }
    //     }
    // }
    // return ans;
  }
};