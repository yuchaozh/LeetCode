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
    ListNode *sortList(ListNode *head) 
    {
        
    }
};






