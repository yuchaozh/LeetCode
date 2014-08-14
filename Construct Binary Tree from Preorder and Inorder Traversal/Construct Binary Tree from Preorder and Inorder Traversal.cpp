/**
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Analysis:
The idea is similar to the previous question. Just be careful with the order of dividing the vector, and the order of preorder root.

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
    TreeNode* ct(vector<int> &preorder, vector<int> &inorder, int ist, int ied, int pst)
    {
        if (ist > ied)
            return NULL;
        TreeNode* res = new TreeNode(preorder[pst]);
        int mid;
        for (int i = ist; i <= ied; i++)
        {
            if (inorder[i] == res->val)
            {
                mid = i;
                break;
            }
        }
        res->left = ct(preorder, inorder, ist, mid - 1, pst + 1);
        res->right = ct(preorder, inorder, mid + 1, ied, pst + 1 + mid - ist);
        return res;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
    {
        if (preorder.size() == 0)
            return NULL;
        else
            return ct(preorder, inorder, 0, inorder.size() - 1, 0);
    }
};