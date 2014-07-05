/**
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Analysis:
Very classic recursive problem.
Check every path of the tree (recursively), with the sum, if find the leaf node with sum==0, then return true.

The way of thinking this problem:
(1) The question requires only true/false return, so the final result is the || operation of all the possible path.
      The return value of the recursion is   go root.left  ||  go root.right
(2) Parameters used in recursion, only the sum and the current node.
(3) Condition:   if the sum == 0 and the node is leaf node return true,
                        if the sum != 0 and the node is NULL, return false
                        else return go root.left, sum-val || go root.right, sum-val
How to define the leaf node? An idea is check the left and right children, all are NULL, then it's a leaf node.


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
    bool hasPathSum(TreeNode *root, int sum) 
    {
        if (!root) {return false;}
        // root->left == NULL && root->right == NULL, then it is a leaf node
        if ((root->left == NULL) && (root->right == NULL) && (sum - root->val == 0)) {return true;}
        return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};