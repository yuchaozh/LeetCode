/**
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Analysis:
The basic idea is still traversing the binary tree in level order (up-down). We can just use a vector to store the nodes and its level, set a pointer, each time move forward one and push its children into the vector. When all the nodes are visited, the vector become the up-down nodes in level order with level information. A simple loop can handle the output requirement.
Details can be easily found in the code below.
The complexity is O(n), n is the number of nodes in the binary tree.

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) 
    {
        if (!root) {return vector<vector<int> > ();}
        vector<pair<TreeNode*, int> > q;
        int lev = 1;
        int count = 0;
        q.push_back(make_pair(root, lev));

        while (count<q.size())
        {
          TreeNode *node = q[count].first;
          lev = q[count].second;
          if (node->left)
          {
            q.push_back(make_pair(node->left, lev + 1));
          }
          if (node->right)
          {
            q.push_back(make_pair(node->right, lev + 1));
          }
          count++;
        }

    vector<vector<int> > res(lev, vector<int>());
    for (int i = 0; i < q.size(); i++)
    {
      res[lev-q[i].second].push_back(q[i].first->val);
    }
    return res;
  }
};