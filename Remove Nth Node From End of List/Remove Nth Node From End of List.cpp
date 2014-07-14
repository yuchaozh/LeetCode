/**
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

More efficient way of solving this problem:
e.g.  1->2->3->4->5->6->7, n=3
Use two pointers:

(1) head->1->2->3->4->5->6->7
     p
     q
   
(2) head->1->2->3->4->5->6->7     // move q, n elements next to p
     p
                         q
(3) head->1->2->3->4->5->6->7    //  q++ ,p++;
               p
                              q
(4) head->1->2->3->4->5->6->7   //  q++ ,p++;
                    p
                                   q
(5) head->1->2->3->4->5->6->7   //  q++ ,p++;
                         p
                                        q
(6) head->1->2->3->4->5->6->7   //  q++ ,p++;
                              p
                                             q
(7) head->1->2->3->4----->6->7   //  delete p->next
                              p
                                             q
return head->next;

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;
        ListNode* q = head;
        int offset = 0;
        while (offset < n)
        {
          q = q->next;
          offset++;
        }
        while (q->next)
        {
          q = q->next;
          p = p->next;
        }
        p->next = p->next->next;
        return head->next;
    }
};