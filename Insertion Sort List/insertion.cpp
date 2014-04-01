/**

Sort a linked list using insertion sort.

The insertion sorting on array can be found in my previous post (here).
The general idea is insert the current element A[i] into the proper position from A[0]...A[i-1], and A[0]...A[i-1] is already sorted.

In this problem, we can use the same idea and linked list provides a more efficient way for insertion.  Details can be found in the code below. Note that after the insertion, the position of P is unchanged but should not provide another p=p->next operation.

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
    ListNode *insertionSortList(ListNode *head) 
    {
        if (head == NULL) {return NULL;}
        ListNode* cursor = new ListNode(0);
        cursor->next = head;
        head = cursor;
        ListNode* current;
        
        // more than one node, at least two nodes
        while (cursor->next != NULL)
        {
        		current = head;
        		bool flag = false;
        		while (current != cursor)
        		{
        				if (current->next->val > cursor->next->val)
        				{
        						ListNode* tmp = cursor->next;
        						cursor->next = cursor->next->next;
        						tmp->next = current->next;
        						current->next = tmp;
        						flag = true;
        						break;
        				}	
        				else
        				{
        						current = current->next;
        				}
        		}
        		if (!flag)
        		{
        				cursor = cursor->next;
        		}
      }
			return head->next;
    }
};
