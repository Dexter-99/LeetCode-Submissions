class Solution
{
public:
  int maxDepth(Node *root)
  {
    if (root == NULL)
      return 0;

    int res = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
      res = max(res, maxDepth(root->children[i]));
    }
    return res + 1;
  }
};