/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  int numComponents(ListNode *head, vector<int> &G)
  {
    int count = 0;
    unordered_set<int> h;
    for (int i = 0; i < G.size(); i++)
      h.insert(G[i]);

    ListNode *curr = head;
    ListNode *parent = NULL;
    while (curr)
    {
      if (parent == NULL)
      {
        if (h.find(curr->val) != h.end())
          count++;
      }
      else
      {
        if (h.find(parent->val) == h.end() && h.find(curr->val) != h.end())
          count++;
      }
      parent = curr;
      curr = curr->next;
    }
    return count;
  }
};