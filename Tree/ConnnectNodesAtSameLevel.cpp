class Solution
{
public:
  //Function to connect nodes at same level.
  void connect(Node *root)
  {
    // Your Code Here
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
      int size = q.size();
      Node *prev = NULL;
      while (size--)
      {
        Node *curr = q.front();
        q.pop();
        if (prev != NULL)
        {
          prev->nextRight = curr;
        }
        prev = curr;
        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }
    }
  }
};