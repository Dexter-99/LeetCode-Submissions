class Solution
{
public:
  bool isLeaf(Node *root)
  {
    if (root == NULL)
      return false;

    if (!root->left && !root->right)
      return true;

    return false;
  }
  void solve1(Node *root, vector<int> &ans)
  {
    Node *curr = root->left;
    while (curr)
    {
      if (!isLeaf(curr))
        ans.push_back(curr->data);
      if (curr->left)
        curr = curr->left;
      else
        curr = curr->right;
    }
  }
  void solve2(Node *root, vector<int> &ans)
  {
    if (root == NULL)
      return;

    if (isLeaf(root))
    {
      ans.push_back(root->data);
      return;
    }
    solve2(root->left, ans);
    solve2(root->right, ans);
  }
  void solve3(Node *root, vector<int> &ans)
  {
    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
      if (!isLeaf(curr))
        temp.push_back(curr->data);
      if (curr->right)
        curr = curr->right;
      else
        curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
      ans.push_back(temp[i]);
  }
  vector<int> printBoundary(Node *root)
  {
    //Your code here
    vector<int> ans;
    if (root == NULL)
      return ans;

    if (!isLeaf(root))
      ans.push_back(root->data);
    solve1(root, ans);
    solve2(root, ans);
    solve3(root, ans);
    return ans;
  }
};