/**
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Analysis:

The idea is using the Tree Traversal.  Consider the Binary Search Tree with InOrder traversal. The result should be a sequence in ascending order, otherwise, it's not a binary search tree.

Note:
We cannot just recursively compare the current node with its left and right child. e.g.
    10
   /     \
 5     15
       /    \
      6   20

When goes to node 15, 6 < 15 and 20 >15, however 6 <10, it's not a BST.

Code (Updated 201403)
We can also use a "min,max" method, to solve the problem. For each node we search its left node and right node, given a min value and max value. Details see the code below:

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
    bool minmax(TreeNode* root, int max, int min)
    {
        if (!root)
            return true;
        if (root->val >= max || root->val <=min)
            return false;
        else
            return minmax(root->left, root->val, min) && minmax(root->right, max, root->val);
    }

    bool isValidBST(TreeNode *root) 
    {
        if (!root)
            return true;
        return minmax(root, INT_MAX, INT_MIN);
    }
};


















