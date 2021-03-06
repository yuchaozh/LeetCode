/**

 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 

Analysis:

using double linked list and combined with map. the head of the list is the LRU. once using one specific node, move that node to the tail.

This a more likely a design question other than a algorithm question, which requires us to choose the proper data structure and implement the "get", "set" methods.

At the first glance, a queue seems enough for this problem, because of its FIFO property. However,  the questions also requires "Recently", which means both "input" and "visit" are "recent actions" for the data. If you have the data "<1,1>"  the least recently used element in the queue <1,1> <2,2><3,3>, if method "get(1)" is called, "<1,1>" is now becoming the last (recently used) element in the queue. (<2,2,><3,3,><1,1>)

Consider the basic operations we need:
(1) Insert a new <key, value> pair to the end of the list.
(2) delete a <key, value> pair (if the cache is full).
(3) move a <key, value> pair to the end. (when it is used)
(3) change the value in a <key, value> pair and move it to the end.

Therefore,  a double linked list can handle the above methods well. A map<key, node*>  is a good way tracking the position of the node according to its key.

Be careful with the following cases:
(1) List is empty
(2) List has one node
(3) Initialization
(4) Don't forget delete the element in the map when it is removed from list.

**/

class LRUCache
{
	struct Node
	{
		Node* prev;
		Node* next;
		int value;
		int key;
		Node(Node* a, Node* b, int k, int v):prev(a), next(b), key(k), value(v){};
		Node(int k, int v):prev(NULL), next(NULL), key(k), value(v){};
	};
	
	map<int, Node*> mp;
	int cp;
	Node* tail;
	Node* head;
public:

    LRUCache(int capacity) 
    {
        cp = capacity;
        //mp.clear();
        head = NULL;
        tail = NULL;
    }
    
    // insert a node at the tail of the double linked list
    void insertNode(Node* node)
    {
    	// the list is empty
    	if (head == NULL)
    		head = tail = node;
    	// else insert at the tail
    	else
    	{
    		tail->next = node;
    		node->prev = tail;
    		tail = node;
    	}
    }
    
    // remove a node from the double linked list
    void rmNode(Node* node)
    {
    	// removed node is head
    	if (node == head)
    	{
    		head = head->next;
    		// if the new head is not null, set prev to NULL
    		if (head != NULL)
    			head->prev = NULL;
    	}
    	// removed node is tail
    	else if (node == tail)
    	{
    		tail = tail->prev;
    		tail->next = NULL;
    	}
    	else
    	{
    		node->prev->next = node->next;
    		node->next->prev = node->prev;
    	}
    }
    
    void moveTail(Node* node)
    {
    	// if there is only one node
    	if (tail == node)
    		return;
    	else if (node == head)
    	{
    		node->next->prev = NULL;
    		head = node->next;
    		
    		tail->next = node;
    		node->prev = tail;
    		node->next = NULL;
    		tail = tail->next;
    		
    	}
    	else
    	{
    		node->prev->next = node->next;
    		node->next->prev = node->prev;
    		
    		tail->next = node;
    		node->next = NULL;
    		node->prev = tail;
    		tail = tail->next;
    	}
    	
    }
    
    int get(int key) 
    {
        if (mp.find(key) == mp.end())
        {
        	return -1;
        }
        else
        {
        	Node* tmp = mp[key];
        	moveTail(tmp);
        	return mp[key]->value;
        }
    }
    
    void set(int key, int value) 
    {
    	// the node exists
        if (mp.find(key) != mp.end())
        {
        	moveTail(mp[key]);
        	mp[key]->value = value;
        }
        // the node not exists
        else
        {
        	// reach the max size, delete the LRU (the head of the double linked list)
        	if (mp.size() == cp)
        	{
        		mp.erase(head->key);
        		rmNode(head);
        	}
        	// insert a new node
        	Node* node = new Node(key, value);
        	mp[key] = node;
        	insertNode(node);
        }
    }
};
