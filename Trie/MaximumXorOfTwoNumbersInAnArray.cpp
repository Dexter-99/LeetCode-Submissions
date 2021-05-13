class TrieNode
{
public:
  TrieNode *child[2];
  TrieNode()
  {
    child[0] = NULL;
    child[1] = NULL;
  }
};
class Solution
{
public:
  void insert(TrieNode *root, int n)
  {
    TrieNode *curr = root;
    for (int i = 31; i >= 0; i--)
    {
      int idx = (n >> i) & 1;
      if (curr->child[idx] == NULL)
      {
        curr->child[idx] = new TrieNode();
      }
      curr = curr->child[idx];
    }
  }
  int maxXor(TrieNode *root, vector<int> &v)
  {
    int _max = INT32_MIN;

    int n = v.size();

    for (int j = 0; j < n; j++)
    {
      int val = v[j];
      int res = 0;
      TrieNode *curr = root;
      for (int i = 31; i >= 0; i--)
      {
        int idx = (val >> i) & 1;

        if (idx == 0)
        {
          if (curr->child[1])
          {
            curr = curr->child[1];
            res += pow(2, i);
          }
          else
          {
            curr = curr->child[0];
          }
        }
        else
        {
          if (curr->child[0])
          {
            curr = curr->child[0];
            res += pow(2, i);
          }
          else
          {
            curr = curr->child[1];
          }
        }
      }
      // cout<<res<<endl;
      _max = max(_max, res);
    }
    return _max;
  }
  int findMaximumXOR(vector<int> &nums)
  {
    TrieNode *root = new TrieNode();
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      insert(root, nums[i]);
    }
    int res = maxXor(root, nums);
    return res;
  }
};