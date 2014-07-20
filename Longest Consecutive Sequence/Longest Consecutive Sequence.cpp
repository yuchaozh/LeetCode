/**
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

Analysis:
Note that it is not the classic DP problem, while this problem tests the data structure other than algorithm.

If there is no O(n) requirement, just sort the array (O(n log n)), then find then longest sequence.
But now, the time is required O(n), first of all, what comes to mind immediately is HASH MAP!!!
Yes, because the hash map search the key->value on O(1). Note that in C++ STL, the map data structure is implemented by BST, so the insert in O(log n), therefore we need to use the unordered_map, which has a O(1) complexity.

We first construct hash map for the array,  then for each element, search 2 directions, +1 and -1. If there is no +1 and -1 in the array, length is 1, remove this from map and go to next element in the array. Save the max length.

In C++ map data structure, .find() returns .end() iterator if not find, and if we use (mp[num[i]]==false), when num[i] key is not in the map, the program will insert the key into the map with a default value, here is false.

**/

class Solution 
{
public:
    int longestConsecutive(vector<int> &num) 
    {
      unordered_map<int, bool> map;
      for (int i = 0; i < num.size(); i++)
      {
        map[num[i]] = true;
      }

      int result = 0;
      for (int i = 0; i < num.size(); i++)
      {
        int max = 1;
        int find = num[i];
        map.erase(num[i]);
        while (map.find(find + 1) != map.end())
        {
          max++;
          map.erase(find + 1);
          find++;
        }
        find = num[i];
        while (map.find(find - 1) != map.end())
        {
          max++;
          map.erase(find - 1);
          find--;
        }
        if (max >= result) {result = max;}
      }
      return result;
    }
};