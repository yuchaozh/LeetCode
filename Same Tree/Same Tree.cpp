/**
Author: Yuchao Zhou


 Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value. 

**/

/**
The most stupid way is using map to count the number of numbers
**/

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
    bool isSameTree(TreeNode *p, TreeNode *q) 
    {
        if (!p && !q)
            return true;
        else if ((!p && q) || (p && !q))
            return false;
        else if ((p->val) != (q->val))
            return false;
        //else if ((p->val) == (q->val))
          //  return true;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
class Solution 
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q) 
    {
    	// the if statement is wrong
        if (!p && !q)
            return true;
        else if ((!p && q) || (p && !q))
            return false;
        else if ((p->val) == (q->val))
            return true;
        else
            return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
**/


















