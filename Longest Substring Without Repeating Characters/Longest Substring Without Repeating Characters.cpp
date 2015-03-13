/**
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

Analysis:
Set two pointers, i,j, scan the string from the start to the end. Set a table to store if the character has occurred.
If s[j] has occurred in S[i..j-1],  compute current length and compare to the max length. Then table[s[i]]=false; i++; If s[j] has not occurred in S[i..j-1], table[s[j]]=true; j++; 

**/

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 1;
        int i = 0;
        int j = 0;
        int maxResult = 0;
        map<char, bool> table;
        /*
         * initially, the table is all false. 
         * if one element is not appeared before, then make it true.
         */
        while ((i < s.size()) && (j < s.size()))
        {
            if (table[s[j]] == false)
            {
                table[s[j]] = true;
                // should include the current one, so plus one
                maxResult = max(maxResult, j - i + 1);
                j++;
            }
            // true means that element appeared before
            // calculate the diatance, here no +1, because the current one should not be included
            // make a new round, initiate the first one and i++
            else if (table[s[j]] == true)
            {
                maxResult = max(maxResult, j - i);
                table[s[i]] = false;
                i++;
            }
        }
        return maxResult;
    }
};