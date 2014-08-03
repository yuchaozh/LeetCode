/**
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Analysis:

The easier way to solve this problem is use the idea as the previous one.
Here present another way of thinking.
In the previous array to BST, we construct the BST in a top-down way. For the list data structure, to get the mid point every time is a waster of time. So construct the BST in a bottom-up way. However, the length of the list must be computed.

Recursively 
1. construct the left tree 
2. construct the root node, list pointer +1.
3. construct the right node

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode* l2bst(ListNode* &head, int st, int ed)
    {
      if (st > ed) {return NULL;}
      TreeNode* leftTree = l2bst(head, st, int(st + (ed - st) / 2) - 1);
      TreeNode* parent = new TreeNode(head->val);
      head = head->next;
      TreeNode* rightTree = l2bst(head, int(st + (ed - st) / 2) + 1, ed);
      parent->left = leftTree;
      parent->right = rightTree;
      return parent;
    }

    TreeNode *sortedListToBST(ListNode *head) 
    {
        if (head == NULL) {return NULL;}
        ListNode* h = head;
        int len = 0;
        while (h)
        {
          len++;
          h = h ->next;
        }
        TreeNode* root = l2bst(head, 1, len);
        return root;
    }
};