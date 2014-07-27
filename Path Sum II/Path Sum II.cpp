/**

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

Analysis:

Recursive like the Question 66, just use a vector<int> to store the result.
Just don't forget the backtracking.
After searching the left node and right node, DO NOT forget to pop the node added in the vector.
Ideas see Question 66.
Details see code below:

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
	vector<vector<int> > allRoute;
	vector<int> route;

	void findRoute(TreeNode* root, int sum)
	{
		if ((root->left == NULL) && (root->right == NULL) && (sum - root->val == 0))
		{
			route.push_back(root->val);
			allRoute.push_back(route);
			return;
		}
		route.push_back(root->val);
		if (root->left != NULL)
		{
			findRoute(root->left, sum - root->val);
			route.pop_back();
		}
		if (root->right != NULL)
		{
			findRoute(root->right, sum - root->val);
			route.pop_back();
		}
	}

    vector<vector<int> > pathSum(TreeNode *root, int sum) 
    {
    	allRoute.clear();
    	route.clear();
    	if (root == NULL) {return allRoute;}
    	findRoute(root, sum);
    	return allRoute;
        
    }
};
