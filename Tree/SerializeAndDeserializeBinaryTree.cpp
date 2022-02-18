/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
  int i;
  // Encodes a tree to a single string.
  string srlize(TreeNode *root)
  {
    if (root == NULL)
      return "";

    string str = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *curr = q.front();
      q.pop();
      if (curr == NULL)
      {
        str += "X,";
      }
      else
      {
        str += to_string(curr->val) + ",";
        q.push(curr->left);
        q.push(curr->right);
      }
    }
    cout << str << endl;
    return str;
  }
  TreeNode *dsrlize(string s)
  {
    if (s == "")
      return NULL;

    stringstream ss(s);
    string str;
    getline(ss, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *curr = q.front();
      q.pop();

      getline(ss, str, ',');
      if (str == "X")
      {
        curr->left = NULL;
      }
      else
      {
        TreeNode *node = new TreeNode(stoi(str));
        curr->left = node;
        q.push(node);
      }
      getline(ss, str, ',');
      if (str == "X")
      {
        curr->right = NULL;
      }
      else
      {
        TreeNode *node = new TreeNode(stoi(str));
        curr->right = node;
        q.push(node);
      }
    }
    return root;
  }
  string serialize(TreeNode *root)
  {
    return srlize(root);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {

    return dsrlize(data);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));