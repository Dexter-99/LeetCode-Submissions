class Solution
{

  class TrieNode
  {
  public:
    bool isEnd;
    TrieNode *a[26];

    TrieNode()
    {
      isEnd = false;
      for (int i = 0; i < 26; i++)
        a[i] = NULL;
    }
  };

public:
  string traverse(TrieNode *root)
  {

    string res = "";
    while (true)
    {
      if (root->isEnd)
        break;
      int j = -1;
      int count = 0;
      for (int i = 0; i < 26; i++)
      {
        if (root->a[i] != NULL)
        {
          j = i;
          count++;
        }
      }
      if (count == 0 || count > 1)
        break;
      res += (char)('a' + j);
      root = root->a[j];
    }
    return res;
  }
  string longestCommonPrefix(vector<string> &strs)
  {
    TrieNode *root = new TrieNode();

    for (int i = 0; i < strs.size(); i++)
    {
      string s = strs[i];
      TrieNode *curr = root;
      for (int j = 0; j < s.length(); j++)
      {
        if (curr->a[s[j] - 'a'] == NULL)
        {
          TrieNode *node = new TrieNode();
          curr->a[s[j] - 'a'] = node;
        }

        curr = curr->a[s[j] - 'a'];
      }
      curr->isEnd = true;
    }
    return traverse(root);
  }
};