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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {

    ListNode *curr = head;
    while (n-- > 1)
    {
      curr = curr->next;
    }
    ListNode *prev = NULL;
    ListNode *node = head;
    while (curr->next)
    {
      prev = node;
      node = node->next;
      curr = curr->next;
    }
    if (prev == NULL)
      return head->next;
    prev->next = node->next;
    return head;
  }
};