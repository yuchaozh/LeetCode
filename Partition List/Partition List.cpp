/**
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

Analysis:
Simple idea but be careful with the operation of pointers.
The idea is:   first get the last element and the length of the list (1 while loop)
                    Then scan the whole list, if current node value < x, then go to the next node.
                                                          if current node value >=x, then move this node to the end of the list.
                    until  meet the length of the original list.

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode* p = new ListNode(0);
    p->next = head;
    head = p;
    ListNode* last = head;

    //if (head == NULL) {return NULL;} //
    if (head->next == NULL) {return head->next;}

    int n = 0;
    while (last->next != NULL) 
    {
      last = last->next;
      n++;
    }
    while (n > 0)
    {
      // using p is confused. normally I will make a new vriable ListNode* traverse. 
      // use traverse to replace p. It is also OK.
      if (p->next->val < x)
      {
        p = p->next;
        n--;
      }
      else
      {
        // using last->next = p->next; Time Limit Exceeded
        last->next = new ListNode(p->next->val);
        last = last->next;
        p->next = p->next->next;
        n--;
      }
    }
    return head->next;
  }
};