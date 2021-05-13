// Recursive Solution
class Solution
{
public:
  ListNode *reverseKGroup(ListNode *head, int k)
  {

    ListNode *curr = head;
    ListNode *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
      ListNode *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
      count++;
    }
    if (count != k)
    {
      curr = prev;
      prev = NULL;
      int count = 0;
      while (curr != NULL && count < k)
      {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
      }
      return prev;
    }
    if (curr != NULL)
    {
      ListNode *list_head = reverseKGroup(curr, k);
      head->next = list_head;
    }
    return prev;
  }
};