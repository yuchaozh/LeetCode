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
class Solution {
public:
    bool valid(vector<int> &l){
        int i=0;
        int j=l.size()-1;
        while (i<j){
            if (l[i++]!=l[j--]){return false;}
        }
        return true;
    }
     
     
    bool isSymmetric(TreeNode *root) {
        vector<int> l;  //store the values in current level
         
        //q1 and q2 stores the current and next level TreeNodes
        queue<TreeNode*> q1; 
        queue<TreeNode*> q2;
         
        if (!root){return true;}
         
        q1.push(root);
        while ((!q1.empty()) || (!q2.empty())){  // exit only when both queue are empty
            if (q2.empty()){   // current level is q1
                while (!q1.empty()){ // push all the q1 nodes' childeren into q2
                    TreeNode* tmp = q1.front();
                    q1.pop(); 
                    l.push_back(tmp->val);
                    if (tmp->val!=-999){ // if current node is not a empty node
                        if (tmp->left!=NULL){q2.push(tmp->left);}
                        else{TreeNode* emp = new TreeNode(-999); q2.push(emp);} // store the empty node for the balance checking 
                        if (tmp->right!=NULL){q2.push(tmp->right);}
                        else{TreeNode* emp = new TreeNode(-999); q2.push(emp);}
                    }
                }
                 
                if (valid(l)==false){return false;}else // all the nodes in current level are stored, check if it is balanced
                {l.clear();}
                 
            }else{  //current level is q2
                while (!q2.empty()){  // push all the q2 nodes' childeren into q1
                    TreeNode* tmp = q2.front();
                    q2.pop();
                    l.push_back(tmp->val);
                    if (tmp->val!=-999){
                        if (tmp->left!=NULL){q1.push(tmp->left);}
                        else{TreeNode* emp = new TreeNode(-999); q1.push(emp);}
                        if (tmp->right!=NULL){q1.push(tmp->right);}
                        else{TreeNode* emp = new TreeNode(-999); q1.push(emp);}
                    }
                }
                 
                if (valid(l)==false){return false;}else
                {l.clear();}
            }
        }
             
        return true;
    }
};