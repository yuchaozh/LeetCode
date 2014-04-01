/**

Sort a linked list in O(n log n) time using constant space complexity.

Analysis:
From the post "Common Sorting Algorithms", we know that the sorting algorithms which have O(n log n) complexity are merge sort and quick sort. So in this problem, we can use merge sort to handle!

Different from array data, this problem requires good understanding of linked list operations, e.g., split, merge.  Before doing this problem, I suggest you first check out the problem "Merge Two Sorted List" and "Linked List Cycle", and also the merge sort algorithm itself. Then the problem becomes pretty straightforward.

Like the merge sort, we can do recursively:
(1) Split the list (slow fast pointers)
(2) sort the first part (merge sort)
(3) sort the second part (merge sort)
(4) merge the two parts (merge two sorted lists)

See the code below for details. In this code, the pointer to the pointer (reference pointer) is used, note that to get the pointer where "ptrRef" points, we can use "*ptrRef".

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
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
    	ListNode* res = new ListNode(0);
        ListNode* cursor = res;
        while (true)
        {
        	if (!l1)
        	{
        		cursor->next = l2;
        		// use break to jump out of the while loop
        		break;
        	}
        	if (!l2)
        	{
        		cursor->next = l1;
        		break;
        	}
        	if (l2->val < l1->val)
        	{
        		cursor->next = l2;
        		l2 = l2->next;
        	}
        	else
        	{
        		cursor->next = l1;
        		l1 = l1->next;
        	}
        	cursor = cursor->next;
        }
        return res->next;
    }
    
    void split(ListNode* head, ListNode** first, ListNode** second)
    {
    		ListNode* current;
    		ListNode* previous;
    		
    		// no node or only has one node
    		if (head == NULL || head->next == NULL)
    		{
    				*first = head;
    				*second = NULL;
    		}
    		else
    		{
    				current = previous = head;
    				while (current != NULL && current->next != NULL)
    				{
    						current = current->next->next;
    						// only has two nodes
    						if (current == NULL)
    						{
    								break;
    						}
    						previous = previous->next;
    				}
    				*first = head;
    				//head->next = NULL;
    				*second = previous->next;
    				// split
    				previous->next = NULL;
    		}
    }
    
    void mergeSort(ListNode** headRef)
    {
    		ListNode* head = *headRef;
    		ListNode* a;
    		ListNode* b;
    		
    		if (head == NULL || head->next == NULL)
    				return;
    		
    		split(head, &a, &b);
    		mergeSort(&a);
    		mergeSort(&b);
    		
    		*headRef = mergeTwoLists(a, b);
    
    }

    ListNode *sortList(ListNode *head) 
    {
        mergeSort(&head);
        return head;
    }
};






