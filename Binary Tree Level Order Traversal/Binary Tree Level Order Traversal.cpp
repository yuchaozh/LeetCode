/**
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Analysis:
The standard way of doing this level traversal is using one queue holding pairs (<treenode, level>). The code is listed below, since the output of this problem is the vectors of each level, just be careful that the last level output (Line 38 in the code).

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
    vector<vector<int> > levelOrder(TreeNode *root) 
    {
        vector<vector<int> > res; //result vector
        queue<pair<TreeNode*, int> > q; // travseral queue
        vector<int> res_tmp; // level vector

        if(!root) {return res;}
        q.push(make_pair(root, 1)); // push the root into the queue
        int level = 1; // previous level
        while(!q.empty())
        {
            pair<TreeNode*, int> tmp = q.front();
            q.pop();
            if(tmp.second != level) // if current element has a new level
            {
                level = tmp.second;
                res.push_back(res_tmp); // push the level vector to the result
                res_tmp.clear();
            }
            res_tmp.push_back(tmp.first->val); // push the current value to the level vector

            if(tmp.first->left != NULL)
            {
                q.push(make_pair(tmp.first->left, tmp.second + 1));
            }
            if (tmp.first->right != NULL)
            {
                q.push(make_pair(tmp.first->right, tmp.second + 1));
            }
        }
        res.push_back(res_tmp); // the last level also needs to push into the result
        return res;
    }
};