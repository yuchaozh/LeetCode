/**
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space? 

trick: node->next;
	   node->next->next;
	   
Head is k nodes from loopstarts
meetingpoint for n1 and n2 is k nodes from loopstart

Author: Yuchao Zhou
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
    ListNode *detectCycle(ListNode *head) 
    {
    	bool hasCycle = false;
		if (head == NULL || head->next == NULL)
			return NULL;
		ListNode* n1 = head;
		ListNode* n2 = head;
		// while(!n2->next == NULL) is wrong.
		// only has two nodes 1, 2
		while(n2->next && n2->next->next)
		{
			n1 = n1->next;
			n2 = n2->next->next;
			if (n1 == n2)
			{
				hasCycle = true;
				break;
			}
		}
		
		// judge has cycle or not
		if (hasCycle == true)
		{
			// let n1 point to the start point, and let n1 and n2 move forward,
			// the meet point is the start of the loop
			n1 = head;
			while (n1 != n2)
			{
				n1 = n1->next;
				n2 = n2->next;
			}
			return n1;
		}
		else
			return NULL;
    }
};
