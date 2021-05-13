class MyQueue
{
public:
  /** Initialize your data structure here. */
  stack<int> pushST;
  stack<int> popST;
  MyQueue()
  {
  }

  /** Push element x to the back of queue. */
  void check()
  {
    if (popST.empty())
    {
      while (!pushST.empty())
      {
        int val = pushST.top();
        pushST.pop();
        popST.push(val);
      }
    }
  }
  void push(int x)
  {
    pushST.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop()
  {
    check();
    int val = popST.top();
    popST.pop();
    return val;
  }

  /** Get the front element. */
  int peek()
  {
    check();
    return popST.top();
  }

  /** Returns whether the queue is empty. */
  bool empty()
  {
    return (pushST.empty() && popST.empty());
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */