/**
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

Idea is to use dfs and only constant space is used. The key is to use the "next" pointer and search right child first then the left child. Details see the code comment.
**/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution 
{
public:
    void dfs(TreeLinkNode* root)
    {
        if (!root) {return;}
        if (root->next == NULL) // if the current node is the right boundary of this level
        {
            if (root->right) // if the node has right clid, set as a boundary (NULL)
            {
                root->right->next = NULL;
            }
            if (root->left)
            {
                root->left->next = root->right;
            }
        }
        else // if the current node has next node in its right
        {
            TreeLinkNode* p = root->next; // the pointer travel along this level
            TreeLinkNode* q = NULL; // the next valid pointer in the level + 1
            while(p) // find the next valid child of root node
            {
                if (p->left) {q = p->left; break;}
                if (p->right) {q = p->right; break;}
                p = p->next;
            }
            if (root->right) {root->right->next = q;} //set right child if exist
            if (root->left && root->right) {root->left->next = root->right;} // set left child if right exist
            if (root->left && !root->right) {root->left->next = q;} // set left child if right not exist
        }
        dfs(root->right); // search right child, order is important, deal with right child first
        dfs(root->left); // search left child
    }

    void connect(TreeLinkNode *root) 
    {
        if (!root) {return;}
        root->next = NULL;
        dfs(root);
    }
};

class Solution
{
public:
    void connect(TreeLinkNode* root)
    {
        queue<pair<TreeLinkNode*, int> > que;
        if (!root) {return;}
        que.push(pair<TreeLinkNode*, int>(root, 1));
        while (!que.empty())
        {
            pair<TreeLinkNode*, int> p = que.front();
            que.pop();
            if (p.first->left != NULL)
            {
                que.push(pair<TreeLinkNode*, int>(p.first->left, p.second + 1));
            }
            if (p.first->right != NULL)
            {
                que.push(pair<TreeLinkNode*, int>(p.first->right, p.second + 1));
            }

            if (p.second != que.front().second)
            {
                p.first->next = NULL;
            }
            else
            {
                p.first->next = que.front().first;
            }
            if (que.empty())
            {
                p.first->next = NULL;
                return;
            }
        }
    }
};