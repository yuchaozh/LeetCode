/**
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Analysis:

Both DFS and BFS can work for this problem. Since the aim is to find the shortest path, BFS might be a better idea. A queue is used to save every node from the binary tree in depth order. Pop each node, and push its left child and right child (if exist). If the current node is the leaf node (no left and right children), return its depth.  To store the depth of each node, we can use a pair structure <TreeNode* int>.

Note: 
pair<TreeNode*, int> is a good data structure to save the node as well as its depth.

pair constructor  :   (1) pair<TreeNode* int>(node, dep);
                        (2) make_pair(node,dep);

**/

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution 
{
public:
    int minDepth(TreeNode* root) 
    {
        queue<pair<TreeNode*, int> > q;
        int i = 0;
        if (!root) {return 0;}
        q.push(make_pair(root, 1));
        while (!q.empty())
        {
            pair<TreeNode*, int> tmp = q.front();
            q.pop();
            //BFS so when first meet leaf node, that is the minimum deepth
            if (!tmp.first->left && !tmp.first->right)
                return tmp.second;
            if (tmp.first->left)
                q.push(make_pair(tmp.first->left, tmp.second + 1));
            if (tmp.first->right)
                q.push(make_pair(tmp.first->right, tmp.second + 1));
        }
    }
};