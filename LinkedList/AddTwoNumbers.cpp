class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *first = l1, *second = l2, *prev = NULL, *res = NULL, *temp = NULL;
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
    return res;
  }
};