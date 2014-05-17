/**
 
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Analysis:
Because the requirement "height balanced", this problem becomes relative easy.
Just recursively use the middle element in the array as the root node of the current tree(sub tree).

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
	TreeNode* cbst(vector<int> &num, int st, int ed)
	{
		if (st > ed)
		{
			return NULL;
		}
		else
		{
			// get the middle one
			int mid = st + (ed - st)/2;
			TreeNode* bst = new TreeNode(num[mid]);
			bst->left = cbst(num, st, mid-1);
			bst->right = cbst(num, mid+1, ed);
			return bst;
		}
	}
	
    TreeNode *sortedArrayToBST(vector<int> &num) 
    {
        if (num.size() == 0) {return NULL;}
        return cbst(num, 0, num.size()-1);
    }
};
