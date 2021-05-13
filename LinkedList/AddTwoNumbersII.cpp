class Solution
{
public:
  ListNode *reverse(ListNode *head)
  {
    ListNode *curr = head, *prev = NULL;
    while (curr != NULL)
    {
      ListNode *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    return prev;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *first = reverse(l1);
    ListNode *second = reverse(l2);
    // cout<<l2->val<<endl;
    ListNode *prev = NULL, *res = NULL, *temp = NULL;
    int carry = 0, sum = 0;
    while (first != NULL || second != NULL)
    {
      int sum = carry + ((first) ? first->val : 0) + ((second) ? second->val : 0);
      carry = sum >= 10 ? 1 : 0;
      sum %= 10;
      temp = new ListNode(sum);

      if (res == NULL)
      {
        res = temp;
      }
      else
      {
        prev->next = temp;
      }
      prev = temp;
      if (first)
        first = first->next;
      if (second)
        second = second->next;
    }
    if (carry)
      temp->next = new ListNode(carry);
    res = reverse(res);
    return res;
  }
};