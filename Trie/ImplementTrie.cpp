class Trie
{
public:
  /** Initialize your data structure here. */
  struct TrieNode
  {
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
      for (int i = 0; i < 26; i++)
      {
        child[i] = NULL;
      }
      isEnd = false;
    }
  };
  TrieNode *root;

  Trie()
  {
    root = new TrieNode();
  }

  /** Inserts a word into the trie. */
  void insert(string word)
  {
    TrieNode *curr = root;
    for (int i = 0; i < word.length(); i++)
    {
      int idx = word[i] - 'a';
      if (curr->child[idx] == NULL)
      {
        curr->child[idx] = new TrieNode();
      }
      curr = curr->child[idx];
    }
    curr->isEnd = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    TrieNode *curr = root;
    for (int i = 0; i < word.length(); i++)
    {
      int idx = word[i] - 'a';
      if (curr->child[idx] == NULL)
      {
        return false;
      }
      curr = curr->child[idx];
    }

    return curr->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    TrieNode *curr = root;
    for (int i = 0; i < prefix.length(); i++)
    {
      int idx = prefix[i] - 'a';
      if (curr->child[idx] == NULL)
      {
        return false;
      }
      curr = curr->child[idx];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */