class BrowserHistory
{

  class Node
  {
  public:
    string val;
    Node *next;
    Node *prev;

    Node(string str)
    {
      val = str;
      next = NULL;
      prev = NULL;
    }
  };

  Node *tail = NULL;
  Node *curr = NULL;

public:
  BrowserHistory(string homepage)
  {
    Node *node = new Node(homepage);
    // tail=node;
    curr = node;
  }

  void visit(string url)
  {
    Node *newNode = new Node(url);
    newNode->prev = curr;
    curr->next = newNode;
    curr = newNode;
  }

  string back(int steps)
  {
    while (steps-- && curr->prev != NULL)
    {
      curr = curr->prev;
    }
    return curr->val;
  }

  string forward(int steps)
  {
    while (steps-- && curr->next != NULL)
    {
      curr = curr->next;
    }
    return curr->val;
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */