class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    int n = 0, m = 0;
    ListNode *curr1 = headA;
    while (curr1 != NULL)
    {
      n++;
      curr1 = curr1->next;
    }
    ListNode *curr2 = headB;
    while (curr2 != NULL)
    {
      m++;
      curr2 = curr2->next;
    }
    curr1 = (n >= m) ? headA : headB;
    curr2 = (curr1 == headA) ? headB : headA;
    int count = abs(n - m);
    while (count--)
    {
      curr1 = curr1->next;
    }
    while (curr1 && curr2 && curr1 != curr2)
    {
      curr1 = curr1->next;
      curr2 = curr2->next;
    }
    return curr2;
  }
};