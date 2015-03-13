/**
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

Analysis:
At the first look, this problem seems wired. Remind the Copy Constructor of a class object, when the class member contains pointers, the direct copy is shadow, we need deep copy. For this problem, there are two major tasks:
(1)  Traverse the graph
(2)  Construct the new graph at the same time.

Traverse the graph is similar to the tree traversal, both DFS and  BFS can be used. Slight difference  is to consider the loop in the graph (e.g., the 2-->2 in the above figure), thus we need store the visited vertex information. If the neighbor of current node has not been visited, then search that node.

Only one point should be noticed for constructing the new graph, in the code below, I used a map< int, node*> to store the visited information, so that if the node has been visited, just add the map[int] to the current node's neighbor list. Be careful the current node is the node you "newed", but not the node in the original graph (line 12 and 13 in the code below. If you set visited[v->label] = v, it is not correct.). 

**/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution 
{
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
  {
    
  }
};