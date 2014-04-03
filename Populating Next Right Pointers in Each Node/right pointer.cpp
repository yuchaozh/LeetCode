/**

 Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

ty.

New updates (201308):
Idea is to use dfs and only constant space is used. The key is to use the "next" pointer and search right child first then the left child. Details see the code comment.

Old solution (BFS):
We know that the tree is full binary tree, which is a very powerful condition that we can use.
As can be seen in the tree above, we need to deal with the nodes according to each level of the tree.
Easily the level-order traversal popped out!
What we need? Yes, just a queue!
What about the level?  Here comes the condition of this problem. A full binary tree which have  ith level have
2^i - 1 nodes.

Once we have the queue, the problem is quite easy. Just make the last node's next pointer NULL, set other nodes' next to the next element in the queue. Well done!

The space needed is less than 2^i-1;


**/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
/**
* DFS function
**/
class Solution 
{
public:
	void dfs(TreeLinkNode* root)
	{
		if (root == NULL) {return;}
		
		if (root->next == NULL)
		{
			if (root->right)
				root->right->next = NULL;
			if (root->left)
				root->left->next = root->right;
		}
		else
		{
			TreeLinkNode* p = root->next;
			TreeLinkNode* q = NULL;
			while(p)
			{
				if (p->left) 
				{
					q = p->left;
					break;
				}
				if (p->right)
				{
					q = p->right;
					break;
				}
				p = p->next;
			}
			if (root->right)
				root->right->next = q;
			if (root->left && root->right)
				root->left->next = root->right;
			if (root->left && !root->right)
				root->left->next = q;				
		}
		
		dfs(root->right);
		dfs(root->left);
	}
    void connect(TreeLinkNode *root) 
    {
        if (!root)
        	return;
        root->next = NULL;
       	dfs(root);
    }
};
 
/**
* BFS function
**/
class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        queue<TreeLinkNode*> que;
        if (root == NULL) {return;}
        que.push(root);
        int i = 1;
        int l = 1;
        while (!que.empty())
        {
        	TreeLinkNode* p = que.front();
        	que.pop();
        	// left first and then right
        	if ((p->right != NULL) && (p->left != NULL))
        	{
        		que.push(p->left);
        		que.push(p->right);
        	}
        	// the right boundary node. 1, 3, 7...
        	if (i == (pow(2, l) - 1))
        	{
        		p->next = NULL;
        		i++;
        		l++;
        	}
        	else
        	{
        		p->next = que.front();
        		i++;
        	}
        }
        
    }
};
	
