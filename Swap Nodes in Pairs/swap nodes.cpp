/**

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Analysis:
This is just a pointer problem which is not that hard to think and implement.
We deal only when the next two nodes exist, e.g. if there are 3 nodes, we only take care of the first 2.
As required only 2 extra ListNodes is needed (definitely you can use only one), to store the current 2 nodes. Then just swap them and link them.
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
    ListNode *swapPairs(ListNode *head) 
    {
        ListNode *p = new ListNode(0);
        p->next = head;
        head = p;
        while (true)
        {
        	if (p->next == NULL) {break;}
        	if (p->next->next == NULL) {break;}
        	ListNode* q1 = p->next;
        	ListNode* q2 = q1->next;
        	q1->next = q2->next;
        	q2->next = q1;
        	p->next = q2;
        	p = q1;
        }
        return head->next;
    }
};
