class Solution
{
public:
  vector<vector<int>> levelOrder(Node *root)
  {
    vector<vector<int>> res;
    if (root == NULL)
      return res;
    vector<int> list;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
      int len = q.size();
      for (int i = 0; i < len; i++)
      {
        Node *curr = q.front();
        q.pop();
        list.push_back(curr->val);
        for (int i = 0; i < curr->children.size(); i++)
        {
          if (curr->children[i] != NULL)
            q.push(curr->children[i]);
        }
      }
      res.push_back(list);
      list.clear();
    }
    return res;
  }
};