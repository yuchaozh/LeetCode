/**
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Analysis:
The idea is simple, add each element of two list with the help of a variable "carry". When both of the lists meet their end, return result.
The key point is to check the carry before return, if carry = 1 the highest bit should be 1, that means add a new node with value "1" to the result list. 
e.g. (9->null) + (1->null) = (0->1->null)

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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
  {
    int carry = 0;
    ListNode* res = new ListNode(0);
    ListNode* head = res;
    while (l1 && l2)
    {
      res->next = new ListNode((l1->val + l2->val + carry) % 10);
      carry = (l1->val + l2->val + carry) / 10;
      l1 = l1->next;
      l2 = l2->next;
      res = res->next;
    }

    // if l1 has left nodes
    while (l1)
    {
      res->next = new ListNode((l1->val + carry) % 10);
      carry = (l1->val + carry) / 10;
      l1 = l1->next;
      res  = res->next;
    }

    // if l2 has left nodes
    while (l2)
    {
      res->next = new ListNode((l2->val + carry) % 10);
      carry = (l2->val + carry) / 10;
      l2 = l2->next;
      res  = res->next;
    }

    // (9->null) + (1->null) = (0->1->null)
    if (carry > 0)
    {
      res->next = new ListNode(carry);
    }
    return head->next;
  }
};