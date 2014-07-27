/**
Write a function to find the longest common prefix string amongst an array of strings.

Analysis:
Note that we have an array of strings, where we only need the common prefix, for all these strings.
In other words, for each char in the strings (starts from [0] ), if they are the same, it is a common prefix, we continue check the next index (e.g., [1] ), if they are the same, we continue check the next (e.g., [2])...  The termination conditions are: (1) one string ends, then the longest prefix is the string itself. (2) The chars of same index are not the same, the longest prefix is the sub string from 0 to current index-1.

So the algorithm is pretty simple, scan from the first character, if it is same for all the strings, go to the next character. Return the string until meet the different character.

**/

class Solution 
{
public:
    string longestCommonPrefix(vector<string> &strs) 
    {
        if (strs.empty()) {return "";}
        if (strs.size() == 1) {return strs[0];}

        for (int i = 0; i < strs[0].size(); i++)
        {
            // judge the j and j + 1, so size() - 1 here
        	for (int j = 0; j < strs.size() - 1; j++)
        	{
        		if (i >= strs[j].size() || strs[j][i] != strs[j + 1][i])
        		{
        			// not include i
        			return strs[j].substr(0, i);
        		}
        	}
        }
        return strs[0];
    }
};