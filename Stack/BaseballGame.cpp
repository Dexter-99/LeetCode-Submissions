// Using Vector
class Solution
{
public:
  int calPoints(vector<string> &ops)
  {
    int sum = 0, val, val1, val2;
    int len = ops.size();
    vector<int> res;
    for (int i = 0; i < len; i++)
    {
      string s = ops[i];
      if (s == "C")
      {
        res.pop_back();
      }
      else if (s == "D")
      {
        val = res[res.size() - 1];
        res.push_back(2 * val);
      }
      else if (s == "+")
      {
        val1 = res[res.size() - 1];
        val2 = res[res.size() - 2];
        res.push_back(val1 + val2);
      }
      else
        res.push_back(stoi(s));
    }
    for (auto x : res)
    {
      sum += x;
    }
    return sum;
  }
};

// Using Stack
class Solution
{
public:
  int calPoints(vector<string> &ops)
  {
    int sum = 0, val, val1, val2;
    int len = ops.size();
    stack<int> st;
    for (int i = 0; i < len; i++)
    {
      string s = ops[i];
      if (s == "C")
      {
        st.pop();
      }
      else if (s == "D")
      {
        st.push(2 * st.top());
      }
      else if (s == "+")
      {
        val1 = st.top();
        st.pop();
        val2 = st.top() + val1;
        st.push(val1);
        st.push(val2);
      }
      else
        st.push(stoi(s));
    }
    while (!st.empty())
    {
      sum += st.top();
      st.pop();
    }
    return sum;
  }
};