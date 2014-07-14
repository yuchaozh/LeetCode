/**

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

Analysis:
Once we see this kind of problem, no matter what sum is required to output, "all root-to-leaf" phrase reminds us the classic Tree Traversal or Depth-First-Search algorithm. Then according to the specific problem, compute and store the values we need. Here in this problem, while searching deeper, add the values up (times 10 + current value), and add the sum to final result if meet the leaf node (left and right child are both NULL).

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
    void dfs(TreeNode* root, int cur, int &res)
    {
        if (root->left == NULL && root->right == NULL)
        {
            cur = cur * 10 + root->val;
            res = res + cur;
        }
        else
        {
            cur = cur * 10 + root->val;
            if (root->left) {dfs(root->left, cur, res);}
            if (root->right) {dfs(root->right, cur, res);}
        }
    }

    int sumNumbers(TreeNode *root) 
    {
        int res = 0;
        if (!root) {return 0;}
        // at he beginning, assume there is only one digit, so cur = 0;
        dfs(root, 0, res);
        return res;
    }
};