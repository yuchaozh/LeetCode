/**
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Analysis:
This is a simple problem, we can use the DFS to solve it. Details see the source code.

**/

class Solution 
{
public:
    // dfs method
    void dfs(string digits, string r, map<char, vector<char> > &map, vector<string> &res)
    {
        if (digits.empty())
        {
            res.push_back(r);
        }
        else
        {
            vector<char> vec = map[digits[0]];
            for (int i = 0; i < vec.size(); i++)
            {
                // substr(1) delete current digit
                dfs(digits.substr(1), r + vec[i], map, res);
            }
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        map<char, vector<char> >mp;
        vector<char> v; // store chars for map
        int n = 2; // the digit start from 2
        for (char i = 'a'; i <= 'z'; i++)
        {
            v.push_back(i);
            if (i == 'c' || i == 'f' || i == 'i' || i == 'l' || i == 'o' || i == 's' || i == 'v' || i == 'z')
            {
                mp[char( n + '0')] = v;
                n++;
                v.clear();
            }
        }
        vector<string> res;
        dfs(digits, "", mp, res);
        return res;
    }
};