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
  ListNode *reverse(ListNode *head)
  {
    ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
  int pairSum(ListNode *head)
  {
    ListNode *slow = head, *prevSlow = NULL, *fast = head;
    while (fast && fast->next)
    {
      prevSlow = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prevSlow->next = NULL;
    ListNode *mid = slow;
    ListNode *head2 = reverse(mid);

    int ans = 0;
    ListNode *curr1 = head, *curr2 = head2;
    while (curr1 && curr2)
    {
      ans = max(ans, curr1->val + curr2->val);
      curr1 = curr1->next;
      curr2 = curr2->next;
    }
    return ans;
  }
};t