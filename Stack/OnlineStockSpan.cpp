class StockSpanner
{
public:
  stack<pair<int, int>> st;
  int top;
  StockSpanner()
  {
    top = -1;
  }

  int next(int price)
  {

    if (top == -1)
    {
      top++;
      st.push({price, top});
      return 1;
    }
    top++;
    while (!st.empty() && st.top().first <= price)
    {
      st.pop();
    }

    int val = (st.empty() ? top + 1 : top - st.top().second);
    st.push({price, top});
    return val;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */