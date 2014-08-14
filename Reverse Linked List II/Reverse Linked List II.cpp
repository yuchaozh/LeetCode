/**
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

Analysis:

In this problem, do not think it too hard, reverse the linked list here is just reverse the value of node.
So the idea is to scan the linked list once, if not meet the reverse sublist, keep going, if reverse done(here the position is the middle of the sublist which needed to be reversed), return, because the latter list do not need any change. While in the sublist, for each element, (1)find the node to be swapped, (2) swap the values.
In the code below, note that,
(1) the stop condition is the middle of the reversed sublist (m+(n-m)/2)
(2) for each element in the sublist, the swapping element is the next (n-m-(i-m)*2) element.
     e.g.
    1-2-3-4-5-6-7-8-9-10-null
        |                        |
      m=2                  n=9
   for 2, just get the next (n-m) element.


    1-9-3-4-5-6-7-8-2-10-null
            |                |
          i=3          idx=8

   next element 3, the swapping element is 8.

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
    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
        ListNode* h = head;
        for (int i = 0; i < n - m; i++)
        {
            int k1 = m + i;
            int k2 = n - i;
            if (k1 > k2)
                return head;
            ListNode* p = h;
            ListNode* q = h;
            while (k1 - 1> 0)
            {
                p = p->next;
                k1--;
            }
            while (k2 - 1 > 0)
            {
                q = q->next;
                k2--;
            }
            int tmp = p->val;
            p->val = q->val;
            q->val = tmp;
        }
        return head;
    }
};