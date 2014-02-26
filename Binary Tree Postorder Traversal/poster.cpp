/*
 * iteration method is from http://yucoding.blogspot.com/2013/12/leetcode-question-binary-tree-postorder.html
 *
 */

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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (!root){return res;}
        st.push(root);
        TreeNode* head=root;
        while (!st.empty()){
            TreeNode* top = st.top();
            if ((top->left==NULL && top->right==NULL)||top->right==head || top->left==head){
                res.push_back(top->val);
                st.pop();
                head = top;
            }else{
                if (top->right!=NULL){st.push(top->right);}
                if (top->left!=NULL){st.push(top->left);}
            }
        }
        return res;
    }
};
  
/**
 * 
 *  recursive solution
 * 
class Solution {
public:
    vector<int> outcome;
    vector<int> postorderTraversal(TreeNode *root) {
        if(root == NULL)  
            return outcome;  
        postorderTraversal(root->left); // 前序遍历左子树  
        postorderTraversal(root->right); // 前序遍历右子树  
        outcome.push_back(root->val);
        return outcome;
    }
};
**/
