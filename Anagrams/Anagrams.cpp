/**
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

Analysis:
Anagrams is two strings are using the same characters. 
One way to compare two strings is use sort(). e.g. 
sort(str1.begin(), str1.end()); 
sort(str1.begin(), str1.end());
if (str1.compare(str2)==0) // when two strings are equal, the func returns 0

A more efficient way:
1. Scan the whole string vector, for each string, store to a hash map with the "ordered string" as the key. O(n).
2. Scan the whole hash map, output the values where for one key the number of value >=2. O(n)

Note:
1. We can use multimap<string, string> in c++, which allows the duplicate key values.
2. To store key-value into multimap, use ".insert(pair<key_type, value_type>(key,value))"
3. Use "pair<multimap<string,string>::iterator,multimap<string,string>::iterator> ret;" and
    ".equal_range()" which returns a iterator pair(ret) that the "first" is the lower bound and "second" is the upper bound, to get all the key-values pairs for one key.
4. To check the number of values in one key, use the .count(key) method.

Updated 201312
Use one map <sorted string as the key,  position of the first string(unsorted)>, can deal with this problem more space efficiently. 
Check the array once, if the current string is not found in the map, then add <sorted string, current position>  into the map. If the current string can be found in the map, then add the current string in the result array, at this time, the first string of this anagram added in the map should also be put into the result array only once! Change the  map value can determine that.

**/

class Solution 
{
public:
  vector<string> anagrams(vector<string> &strs) 
  {
    vector<string> res;
    map<string, int> mp; // store sorted string, position of unsorted string
    for (int i = 0; i < strs.size(); i++)
    {
      string ss = strs[i];
      // sort the string
      sort(ss.begin(), ss.end());
      // find the string in the map
      if (mp.find(ss) != mp.end())
      {
        res.push_back(strs[i]);
        if (mp[ss] != -1)
        {
          // add first unsorted target string to the result
          res.push_back(strs[mp[ss]]);
          mp[ss] = -1;
        }
      }
      else
      {
        mp[ss] = i;
      }
    }
    return res;
  }
};