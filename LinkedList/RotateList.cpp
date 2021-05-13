class Solution
{
public:
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (head == NULL)
      return head;
    int n = 0;
    ListNode *curr = head;
    ListNode *prev = NULL;
    while (curr != NULL)
    {
      prev = curr;
      curr = curr->next;

      n++;
    }
    k %= n;
    if (k == 0)
      return head;

    prev->next = head;
    int count = 0;
    while (count < (n - k))
    {
      prev = prev->next;
      count++;
    }
    ListNode *newHead = prev->next;
    prev->next = NULL;

    return newHead;
  }
};