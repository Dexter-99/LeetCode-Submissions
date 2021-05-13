class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    if (l1 == NULL)
      return l2;
    if (l2 == NULL)
      return l1;
    ListNode *curr1 = l1;
    ListNode *curr2 = l2;
    ListNode *res = NULL, *prev = NULL, *temp = NULL;
    while (curr1 != NULL && curr2 != NULL)
    {
      if (curr1->val <= curr2->val)
      {
        temp = curr1;
        curr1 = curr1->next;
      }
      else
      {
        temp = curr2;
        curr2 = curr2->next;
      }
      if (res == NULL)
      {
        res = temp;
      }
      else
      {
        prev->next = temp;
      }
      prev = temp;
    }
    if (curr1 != NULL)
      prev->next = curr1;
    if (curr2 != NULL)
      prev->next = curr2;
    return res;
  }
};