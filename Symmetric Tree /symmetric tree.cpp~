/**

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

Analysis:
Use two queue to store each level of nodes back and force instead of storing the level.
Use a special node to store the empty node. (-999 in the code below).
Details see the comments in the code below.

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
    bool isSymmetric(TreeNode *root) 
    {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        if (!root) {return true;}
        
        q1.push(root);
        while ((!q1.empty()) || (!q2.empty()))
        {
        	if (q2.empty())
        	{
        		while (!q1.empty())
        		{
        			TreeNode* tmp = q1.front();
        			q1.pop();
        			l.push_back(tem->val);
        			if (tmp->val != -99)
        		}
        	}
        }
    }
};
