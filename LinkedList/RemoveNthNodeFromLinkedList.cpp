class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;
    for (int i = 0; i < n; i++)
    {
      if (fast == NULL)
        return NULL;
      fast = fast->next;
    }
    while (fast != NULL)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next;
    }
    if (prev == NULL)
      return slow->next;

    prev->next = slow->next;
    return head;
  }
};