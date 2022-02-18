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
  class myCmp
  {
  public:
    bool operator()(ListNode *a, ListNode *b)
    {
      return a->val > b->val;
    }
  };

public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    ListNode *head = new ListNode(0);
    ListNode *curr = head;
    priority_queue<ListNode *, vector<ListNode *>, myCmp> pq;
    for (int i = 0; i < lists.size(); i++)
    {
      if (lists[i] != NULL)
        pq.push(lists[i]);
    }

    while (!pq.empty())
    {
      ListNode *newNode = pq.top();
      pq.pop();
      if (newNode->next)
      {
        pq.push(newNode->next);
      }
      // cout<<newNode->val<<endl;

      curr->next = newNode;

      curr = curr->next;
    }
    return head->next;
  }
};