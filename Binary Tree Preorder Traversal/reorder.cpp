/**
 * Author: Yuchao Zhou
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * use stack to iterate. Can not use queue.
 * using stack can travse left children firstly, then right 	 children. queue is one left, one right, but cannot separate all left and all right.
 * 
 **/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> outcome;
        stack<TreeNode*> input;
        if (root == NULL)
            return outcome;
        input.push(root);
        while (!input.empty())
        {
            TreeNode* popout = input.top();
            // pop() is void function, will not return the first element.
            input.pop();
            outcome.push_back(popout->val);
            if (popout->right != NULL)
                input.push(popout->right);
            if (popout->left != NULL)
                input.push(popout->left);
        }
        return outcome;
    }
};


/**
 * 
 * recursive
 * 
 **/
class Solution {
public:
    vector<int> outcome;
    vector<int> preorderTraversal(TreeNode *root) {
        if(root == NULL)  
            return outcome;  
        outcome.push_back(root->val);
        preorderTraversal(root->left); // 前序遍历左子树  
        preorderTraversal(root->right); // 前序遍历右子树  
        return outcome;
    }

};
