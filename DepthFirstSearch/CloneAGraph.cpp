/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
  Node *cloneGraph(Node *node)
  {
    if (node == NULL)
      return node;
    unordered_map<Node *, Node *> mp;
    Node *cloneNode = new Node(node->val);
    queue<Node *> q;
    q.push(node);
    mp[node] = cloneNode;
    while (!q.empty())
    {
      Node *curr = q.front();
      q.pop();
      // cout<<curr->val<<endl;
      for (auto v : curr->neighbors)
      {

        if (mp.find(v) == mp.end())
        {
          mp[v] = new Node(v->val);
          q.push(v);
        }
        mp[curr]->neighbors.push_back(mp[v]);
      }
    }
    return cloneNode;
  }
};