/**
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Analysis:
This problem returns a new linked list, which has the same value and structure of the original one. First we can create a new linked list without considering the Random pointer, which is straight forward:  Scan every node in the original list and create the new list (line 21- 27 in the code below).

But how to keep the random pointer also correct ? If we only point the new random pointer to the original random pointer, which is not a deep copy (since the deletion of nodes in original list will delete the new one as well).  So, how to memorize the relative position of the random node to the current node? Firstly I think to use the length from head node to the random node. For each node, I stored the position of its random node, same position node in the new list is the random node for the node in the new list. This idea can work, but is not efficient. For every node you have to search from the start to the end to find the random, the total complexity is O(n^2). Can we quickly locate the position of the node?  Yes!  Hash map!  A map with the node as key and node as the value can finish the job! We can use the original list node as the key, and the same node in the new list as the value.  Now the map[node_old] = node_new, therefore the node_new->random = map[node_old->random]. In this way, the complexity decreases to O(n).

**/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution 
{
public:
  RandomListNode *copyRandomList(RandomListNode *head) 
  {
    if (!head) {return NULL;}
    map<RandomListNode*, RandomListNode*> mp; // map <originalNode, newNode>
    mp.clear();
    // create a new linked list
    RandomListNode* res = new RandomListNode(0);
    // original point
    RandomListNode* p = head;
    // new list point
    RandonListNode* q = res;

    // first step:
    // copy original list
    while (p)
    {
      RandomListNode* tmp = new RandomListNode(p->label);
      q->next = tmp;
      mp[p] = tmp;
      p = p->next;
      q = q->next;
    }

    // second step:
    // copy random points
    p = head;
    q = res->next;
    while (p)
    {
      if (p->random == NULL)
        q->random = NULL;
      else
        q->random = mp[p->random];
      p = p->next;
      q = q->next;
    }
    return res->next;
  }
};