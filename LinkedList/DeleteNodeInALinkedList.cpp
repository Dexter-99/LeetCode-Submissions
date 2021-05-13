// When You are given the pointer to the node itself rather than the head of the list
class Solution
{
public:
  void deleteNode(ListNode *node)
  {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};