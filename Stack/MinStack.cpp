class MinStack
{
  stack<int> st;
  stack<int> as;

public:
  /** initialize your data structure here. */
  MinStack()
  {
  }

  void push(int x)
  {
    st.push(x);
    if (as.empty() || as.top() >= x)
    {
      as.push(x);
    }
  }

  void pop()
  {
    if (as.top() == st.top())
    {
      as.pop();
    }
    st.pop();
  }

  int top()
  {
    return st.top();
  }

  int getMin()
  {
    return as.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */