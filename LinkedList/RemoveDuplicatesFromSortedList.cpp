class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
      if (curr->val == curr->next->val)
      {
        ListNode *curr_next = curr->next->next;
        curr->next = curr_next;
      }
      else
      {
        curr = curr->next;
      }
    }
    return head;

    return head;
  }
};