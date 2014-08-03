/**
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Analysis:
The idea is much similar to the previous question "Binary Tree Level Order Traversal", the only difference is the print order for each level. Note that we store the level order while traverse the tree, otherwise the print could be a mass. Just consider the order when pushing the values into the result vector. deque is a good STL container which can deal with double-end push and pop operation.

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
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
  {
    vector<vector<int> > res;
    if (root != NULL)
    {
      res.push_back(vector<int> (1, root->val));
      deque<TreeNode* > q1, q2;
      vector<int> lev;
      q1.push_back(root);
      bool flag = false; // print order
      while (true)
      {
        while (!q1.empty())
        {
          TreeNode* node = q1.front();
          q1.pop_front();
          if (node->left != NULL) 
            q2.push_back(node->left);
          if (node->right != NULL)
            q2.push_back(node->right);
        }
        if (q2.empty())
          return res;
        q1 = q2;
        while (!q2.empty())
        {
          if (flag) // true, front to back
          {
            lev.push_back(q2.front()->val);
            q2.pop_front();
          }
          else // false, back to front
          {
            lev.push_back(q2.back()->val);
            q2.pop_back();
          }
        }
        res.push_back(lev);
        lev.clear();
        flag = !flag;
      }
    }
    return res;
  }
};