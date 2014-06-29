/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

Analysis:
The classic question from the Cracking the Code Interview. DFS is enough. Note that it is wrong when the number of ')' is more than '(' in the current string. e.g. ()()).

**/

class Solution 
{
public:
    void gp(string str, int l, int r, int &n, vector<string> &res)
    {
        if (l > n) {return;}
        if (l == n && r == n)
        {
            res.push_back(str);
        }
        else
        {
            gp(str + "(", l + 1, r, n, res);
            if (l > r)
            {
                gp(str + ")", l, r + 1, n, res);
            }
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        if (n == 0) {return res;}
        gp("", 0, 0, n, res);
        return res;
    }
};