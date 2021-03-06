/**

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Analysis:


The idea is relative simple, add one list into the other.
Consider the following conditions:
1. The l1 is empty. Then l2 is the result.
2. current element in l1 > current element in l2, insert current element in l2 before current element of l1.
3. current element in l1 < current element in l2, goto the next element in l1 and compare again.
Step 2 and 3 are in the loop, until l2 is empty.

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
        // build a new head, which can make changement of pointers easily
        ListNode *res = new ListNode(0);
        ListNode *cursor = res;
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
        // return the list after the head
        return res->next;
    }
};

