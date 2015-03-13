/**
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Analysis:
The easiest way is to use 2 loops, search every pair of elements, find the result and return the index. The idea is simple but the complexity is high ( O(n^2) ).

Let's think in another way, the above idea tracks the forward way:   A[i]+A[j]==target. 
What about the opposite way?   target-A[i]==A[j].

Yep! So for each element A[i], if we know there exists A[j]== target-A[i], and the i<j, then OK!

Thus, we use hash map to store the numbers, scan the whole table and use map.find() function to find the existence of the elements. Note that the question requires (1) the index order, (2) the index is the array number +1.

**/

// O(n^2)
class Solution 
{
public:
  vector<int> twoSum(vector<int> &numbers, int target) 
  {
    vector<int> res;
    // i < numbers.size() - 1, so j = i + 1
    // due to we loop from left to right so there is no need to judge 
    // while number is smaller or bigger
    for (int i = 0; i < numbers.size() - 1; i++)
    {
      // j = i + 1: do not use one elemet twice
      for (int j = i + 1; j < numbers.size(); j++)
      {
        if (numbers[i] + numbers[j] == target)
        {
          // plus 1 is the index of the result element
          res.push_back(i + 1);
          res.push_back(j + 1);
          return res;
        }
      }
    }
    return res;
  }
};

// O(n)
class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    vector<int> res;
    map<int, int> mp; // (value, index) pair
    mp.clear();

    // put numbers into hashmap
    for (int i = 0; i < numbers.size(); i++)
    {
      mp[numbers[i]] = i;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
      // find target result
      if (mp.find(target - numbers[i]) != mp.end())
      {
        // make sure index1 is less than index2
        // cause it is sorted so we just use index to indicate the number
        if (i < mp[target - numbers[i]])
        {
          res.push_back(i + 1);
          res.push_back(mp[target - numbers[i]] + 1);
          return res;
        }
        if (i > mp[target - numbers[i]])
        {
          res.push_back(mp[target - numbers[i]] + 1);
          res.push_back(i + 1);
          return res;
        }
      }
    }
  }
};